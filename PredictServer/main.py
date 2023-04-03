from flask import Flask, jsonify, request
from psycopg2 import connect, sql
import psycopg2
import os
import random
import time
import logging


app = Flask(__name__)
app.run(debug=True)

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
    image = request.files['image']
    time = request.form['time']
    type = 'unknown'

    # сохранение картинки на диск
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
if __name__ == '__main__':
    app.run(debug=True)
