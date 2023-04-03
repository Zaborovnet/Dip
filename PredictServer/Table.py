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
filename = "0.png"
data = {'number': 1, 'longitude': 25, 'latitude': 123, 'image': open(filename, "rb"), 'time': str(datetime.datetime.now())}

response = requests.post(url, data=data)

if response.status_code == 200:
    print('User added successfully')
else:
    print('Error adding user:', response.content)