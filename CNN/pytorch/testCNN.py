import random
from typing import Callable, Tuple

from kornia import augmentation as aug
from kornia import filters
from kornia.geometry import transform as tf
import torch
from torch import nn, Tensor
from torch.utils.data import DataLoader
from torchvision import datasets, transforms, models
from torchvision.transforms import ToTensor
from copy import deepcopy
from itertools import chain
from typing import Dict, List
import pytorch_lightning as pl
from torch import optim
import torch.nn.functional as f
from typing import Union
import timm
import gc
gc.collect()
from os import cpu_count
from torch.utils.data import DataLoader
import os
from koila import lazy

#Tests
import torch
import torchvision
import numpy as np
import matplotlib
matplotlib.use("QtAgg")
#import matplotlib.pyplot as plt
from matplotlib import pyplot as plt
import torch.nn as nn
import torch.nn.functional as F
from torchvision.datasets import CIFAR10
from torchvision.transforms import ToTensor
from torchvision.utils import make_grid
from torch.utils.data.dataloader import DataLoader
from torch.utils.data import random_split
from IPython.display import set_matplotlib_formats


import warnings
warnings.filterwarnings("ignore")
from torchvision.datasets import ImageFolder
from torchvision.transforms import ToTensor

class RandomApply(nn.Module):
    def __init__(self, fn: Callable, p: float):
        super().__init__()
        self.fn = fn
        self.p = p

    def forward(self, x: Tensor) -> Tensor:
        return x if random.random() > self.p else self.fn(x)


def default_augmentation(image_size: Tuple[int, int] = (224, 224)) -> nn.Module:
    return nn.Sequential(
        tf.Resize(size=image_size),
        RandomApply(aug.ColorJitter(0.8, 0.8, 0.8, 0.2), p=0.8),
        aug.RandomGrayscale(p=0.2),
        aug.RandomHorizontalFlip(),
        RandomApply(filters.GaussianBlur2d((3, 3), (1.5, 1.5)), p=0.1),
        aug.RandomResizedCrop(size=image_size),
        aug.Normalize(
            mean=torch.tensor([0.485, 0.456, 0.406]),
            std=torch.tensor([0.229, 0.224, 0.225]),
        ),
    )


def mlp(dim: int, projection_size: int = 256, hidden_size: int = 4096) -> nn.Module:
    return nn.Sequential(
        nn.Linear(dim, hidden_size),
        nn.BatchNorm1d(hidden_size),
        nn.ReLU(inplace=True),
        nn.Linear(hidden_size, projection_size),
    )

class EncoderWrapper(nn.Module):
    def __init__(
        self,
        model: nn.Module,
        projection_size: int = 256,
        hidden_size: int = 4096,
        layer: Union[str, int] = -2,
    ):
        super().__init__()
        self.model = model
        self.projection_size = projection_size
        self.hidden_size = hidden_size
        self.layer = layer

        self._projector = None
        self._projector_dim = None
        self._encoded = torch.empty(0)
        self._register_hook()

    @property
    def projector(self):
        if self._projector is None:
            self._projector = mlp(
                self._projector_dim, self.projection_size, self.hidden_size
            )
        return self._projector

    def _hook(self, _, __, output):
        output = output.flatten(start_dim=1)
        if self._projector_dim is None:
            self._projector_dim = output.shape[-1]
        self._encoded = self.projector(output)

    def _register_hook(self):
        if isinstance(self.layer, str):
            layer = dict([*self.model.named_modules()])[self.layer]
        else:
            layer = list(self.model.children())[self.layer]

        layer.register_forward_hook(self._hook)

def normalized_mse(x: Tensor, y: Tensor) -> Tensor:
    x = f.normalize(x, dim=-1)
    y = f.normalize(y, dim=-1)
    return 2 - 2 * (x * y).sum(dim=-1)

class SupervisedLightningModule(pl.LightningModule):


    def __init__(self, model: nn.Module, **hparams):
        super().__init__()
        self.model = model
        self.validation_step_outputs = []

    def forward(self, x: Tensor) -> Tensor:
        return self.model(x)

    def configure_optimizers(self):
        optimizer = getattr(optim, self.hparams.get("optimizer", "Adam"))
        lr = self.hparams.get("lr", 1e-4)
        weight_decay = self.hparams.get("weight_decay", 1e-6)
        return optimizer(self.parameters(), lr=lr, weight_decay=weight_decay)

    def training_step(self, batch, *_) -> Dict[str, Union[Tensor, Dict]]:
        x, y = batch
        loss = f.cross_entropy(self.forward(x), y)
        self.log("train_loss", loss.item())
        return {"loss": loss}

    @torch.no_grad()
    def validation_step(self, batch, *_) -> Dict[str, Union[Tensor, Dict]]:
        x, y = batch
        loss = f.cross_entropy(self.forward(x), y)
        self.validation_step_outputs.append(loss)
        return loss

    @torch.no_grad()
    def on_validation_epoch_end(self) -> Dict:
        epoch_average = torch.stack(self.validation_step_outputs).mean()
        self.log("validation_epoch_average", epoch_average)
        self.validation_step_outputs.clear()  # free memory

train_transform=transforms.Compose([
        transforms.RandomRotation(10),      # rotate +/- 10 degrees
        transforms.RandomHorizontalFlip(),  # reverse 50% of images
        transforms.Resize(224),             # resize shortest side to 224 pixels
        transforms.CenterCrop(224),         # crop longest side to 224 pixels at center
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406],
                             [0.229, 0.224, 0.225])
])


DATASET=datasets.ImageFolder(root=("data/drone_or_bird1"),transform=train_transform)
#DATASET=datasets.ImageFolder(root=("data/FF"),transform=train_transform)

#class_names=DATASET.classes
#print(class_names)
#print(len(class_names))

class_names=DATASET.classes
print(class_names)
print(len(class_names))

train_size = int(0.8 * len(DATASET))
val_size = len(DATASET) - train_size
TRAIN_DATASET, TEST_DATASET = torch.utils.data.random_split(
    DATASET, [train_size, val_size]
)


from torchvision.models import resnet18

mlp = resnet18()
mlp=model1 = timm.create_model('vit_base_patch16_224')
mlp.load_state_dict(torch.load('NewTT2.pth'))
mlp.eval()


#def accuracy(pred: Tensor, labels: Tensor) -> float:
    #return (pred.argmax(dim=-1) == labels).float().mean().item()

#acc = sum([accuracy(mlp(x), y) for x, y in val_loader]) / len(val_loader)
#print(f"Accuracy: {acc:.3f}")

def to_device(data, device):
    """Move tensor(s) to chosen device"""
    if isinstance(data, (list, tuple)):
        return [to_device(x, device) for x in data]
    return data.to(device, non_blocking=True)
def predict_image(img, model):
    # Convert to a batch of 1
    xb = img.unsqueeze(0)
    # Get predictions from model
    yb = model(xb)
    # Pick index with highest probability
    _, preds  = torch.max(yb, dim=1)
    # Retrieve the class label
    return DATASET.classes[preds[0].item()]

for i in range (10):
    img, label = TEST_DATASET[i]
    plt.imshow(img.permute(1, 2, 0))
    print('Label:', DATASET.classes[label], ', Predicted:', predict_image(img, mlp))
    plt.savefig('data/FF/objects/to.png')
    plt.show()


