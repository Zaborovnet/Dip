import psycopg2
import os
import random
import time
import requests
import datetime


conn = psycopg2.connect(
    dbname='objects',
    user='root',
    password='root',
    host='localhost',
    port='5432'
)
cur = conn.cursor()

cur.execute('SELECT * FROM targets')
rows = cur.fetchall()
for row in rows:
    print(row)
url = 'http://localhost:5000/'
filename = '0.png'

#data = {'number': 123, 'longitude': 45.123, 'latitude': -123.456, 'image': open(filename, "rb"), 'time': str(datetime.datetime.now())}
response = requests.post('http://localhost:5000/', data={'number': 1, 'longitude': 45.678, 'latitude': 32.123, 'time': str(datetime.datetime.now()), 'type': 'unknown'}, files={'image': open('0.png', 'rb')})
#response = requests.post(url, data=data)
print(response.status_code)
print(response.text)
if response.status_code == 200:
    print('User added successfully')
else:
    print('Error adding user:', response.content)