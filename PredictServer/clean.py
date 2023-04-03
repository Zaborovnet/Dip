import psycopg2
import os
import random
import time
import requests
import datetime

# запуск и очистка БД
#response = requests.get('http://localhost:5000/', params={'START_BD': True})
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