import requests
import json
import random

# параметры для подключения к серверу
url = 'http://localhost:5000/'
headers = {'Content-Type': 'application/json'}

# создание нового объекта
data = {
    "number": 123,
    "longitude": 55.755826,
    "latitude": 37.6172999,
    "time": "2022-06-01T10:00:00.000Z"
}
response = requests.post(url, headers=headers, json=data)
print(response.status_code)

# изменение координат уже существующих объектов
response = requests.get(url)
targets = json.loads(response.text)

for target in targets:
    # генерация новых координат
    new_longitude = target['longitude'] + random.uniform(-0.001, 0.001)
    new_latitude = target['latitude'] + random.uniform(-0.001, 0.001)

    # отправка запроса на изменение координат
    data = {
        "longitude": new_longitude,
        "latitude": new_latitude,
        "time": "2022-06-01T10:00:00.000Z"
    }
    put_url = url + str(target['number'])
    response = requests.put(put_url, headers=headers, json=data)
    print(response.status_code)