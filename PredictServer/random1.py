import requests
import json
import random
import datetime
# Чтение файла с картинкой
with open('0.png', 'rb') as file:
    img_data = file.read()
# параметры для подключения к серверу
url = 'http://localhost:5000/'
headers = {'Content-Type': 'application/json'}
# создание нового объекта
for i in range(10):
    data = {     "number": i,
                 "longitude": 55.755826,
                 "latitude": 37.6172999,
                 "time": str(datetime.datetime.now()) }
    files = {     'image': img_data }
    response = requests.post(url, data=data, files=files)
    print(response.status_code)
# изменение координат уже существующих объектов
response = requests.get('http://localhost:5000/')
if response.status_code == 200:
    targets = json.loads(response.text)
    while True:
        for target in targets:
            print (targets)
            print (targets)
            #генерация новых координат
            new_longitude = target['longitude'] + random.uniform(-0.01, 0.01)
            new_latitude = target['latitude'] + random.uniform(-0.01, 0.01)
             #отправка запроса на изменение координат
            data = {
                "number": target['number'],
                "longitude": new_longitude,
                "latitude": new_latitude,
                "time": str(datetime.datetime.now())}
            response = requests.put(url, data=data)
            print(response.status_code)

else:
    print("Error: status code ", response.status_code)