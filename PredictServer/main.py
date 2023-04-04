from flask import Flask, jsonify, request
from psycopg2 import connect, sql
import psycopg2
import os
import random
import time
import logging
from PIL import Image
from io import BytesIO

import torch
from PIL import Image
from flask import Flask, request, jsonify
import timm
import torchvision.transforms as transforms
import io
from torchvision import datasets, transforms, models



app = Flask(__name__)
if __name__ == '__main__':
    app.run(debug=True)
# Load the pre-trained model
model = timm.create_model('vit_base_patch16_224')
model.load_state_dict(torch.load('NewTT2.pth', map_location=torch.device('cpu')))
model.eval()
# Определение функции преобразования изображения
transform = transforms.Compose([
        transforms.Resize(224),
        transforms.CenterCrop(224),
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406],
                             [0.229, 0.224, 0.225])
])
DATASET=datasets.ImageFolder(root=("data/drone_or_bird1"),transform=transform)

@app.route('/', methods=['START_BD'])
def start_targets():
    # настройки подключения к БД
    conn = psycopg2.connect(
        dbname='objects',
        user='root',
        password='root',
        host='localhost',
        port='5432'
    )
    cur = conn.cursor()
    sql = ''' DROP TABLE targets '''
    cur.execute(sql)
    conn.commit()

    cur.execute(
        'CREATE TABLE targets (id serial PRIMARY KEY,number INTEGER NOT NULL, longitude FLOAT NOT NULL, latitude FLOAT NOT NULL, type TEXT NOT NULL, time TIMESTAMP NOT NULL)')
    conn.commit()
@app.route('/', methods=['GET'])
def get_targets():
    # получение последних созданных объектов
    conn = psycopg2.connect(
        dbname='objects',
        user='root',
        password='root',
        host='localhost',
        port='5432'
    )

    cursor = conn.cursor()

    cursor.execute("""
        SELECT number, longitude, latitude, type, time
        FROM targets
        ORDER BY time DESC
        LIMIT 10
    """)
    rows = cursor.fetchall()

    targets = []
    for row in rows:
        targets.append({
            'number': row[0],
            'longitude': row[1],
            'latitude': row[2],
            'type': row[3],
            'time': row[4].strftime('%Y-%m-%d %H:%M:%S')
        })

    cursor.close()
    conn.close()

    return jsonify(targets)

@app.route('/', methods=['POST'])
def create_target():
    # создание нового объекта
    number = request.form['number']
    longitude = request.form['longitude']
    latitude = request.form['latitude']
    file = request.files['image']
    time = request.form['time']

    from PIL import Image
    def predict_image(img, model):
        xb = img.unsqueeze(0)
        yb = model(xb)
        _, preds = torch.max(yb, dim=1)
        return DATASET.classes[preds[0].item()]

    # Определение картинки для предсказания класса объекта на основе изображения
    img = Image.open(file).resize((224, 224))
    img = img.convert('RGB')
    img = transforms.ToTensor()(img)
    predicted = predict_image(img, model)
    type = predicted
    # ...

    conn = psycopg2.connect(
        dbname='objects',
        user='root',
        password='root',
        host='localhost',
        port='5432'
    )

    cursor = conn.cursor()

    cursor.execute(sql.SQL("""
        INSERT INTO targets (number, longitude, latitude, type, time)
        VALUES ({number}, {longitude}, {latitude}, {type}, {time})
    """).format(
        number=sql.Literal(number),
        longitude=sql.Literal(longitude),
        latitude=sql.Literal(latitude),
        type=sql.Literal(type),
        time=sql.Literal(time)
    ))
    conn.commit()

    cursor.close()
    conn.close()

    return '', 204

@app.route('/', methods=['PUT'])
def update_target():
    # изменение долготы, широты и времени объекта по номеру
    number = request.form['number']
    longitude = request.form['longitude']
    latitude = request.form['latitude']
    time = request.form['time']

    conn = psycopg2.connect(
        dbname='objects',
        user='root',
        password='root',
        host='localhost',
        port='5432'
    )

    cursor = conn.cursor()

    cursor.execute(sql.SQL("""
        UPDATE targets
        SET longitude = {longitude},
            latitude = {latitude},
            time = {time}
        WHERE number = {number}
    """).format(
        longitude=sql.Literal(longitude),
        latitude=sql.Literal(latitude),
        time=sql.Literal(time),
        number=sql.Literal(number)
    ))
    conn.commit()

    cursor.close()
    conn.close()

    return '', 204