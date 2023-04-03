import psycopg2
import os
import random
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler


conn = psycopg2.connect(
    dbname='objects',
    user='root',
    password='root',
    host='localhost',
    port='5432'
)

cur = conn.cursor()


sql = ''' DROP TABLE locations '''
cur.execute(sql)
conn.commit()

cur.execute('CREATE TABLE locations (id serial PRIMARY KEY, lon float, lat float)')
conn.commit()
cur.execute('SELECT * FROM locations')
rows = cur.fetchall()
for row in rows:
    print(row)

#lat = 37.7749
#long = -122.4194
#cur.execute("INSERT INTO locations (lon, lat)  VALUES (%s, %s)", (lat, long))
#cur.execute("SELECT id FROM locations WHERE lon=%.4f AND lat=%.4f" % (lat, long))
#record = cur.fetchone()
#print("ID:", record[0])
with open("coordinates.txt") as f:
    for line in f.readlines():
        lat, long = line.strip().split(",")
        cur.execute("INSERT INTO locations (lon, lat) VALUES (%s, %s)", (lat, long))
        cur.execute("SELECT id FROM locations WHERE lon=%s AND lat=%s", (lat, long))
        record = cur.fetchone()

    # for line in f:
    # x, y = line.strip().split(",")
    # cur.execute(f"INSERT INTO locations (lon, lat) VALUES ({x}, {y})")

    conn.commit()

def write_to_db(coords):
    conn = psycopg2.connect(
        dbname='objects',
        user='root',
        password='root',
        host='localhost',
        port='5432'
    )
    cursor = conn.cursor()
    cursor.execute("INSERT INTO locations (lon, lat) VALUES (%s, %s)", (coords[0], coords[1]))
    conn.commit()
    cursor.close()
    conn.close()
# класс для отслеживания изменений в файле
class FileHandler(FileSystemEventHandler):
    def on_modified(self, event):
        if not event.is_directory:  # проверка на изменения в директории
            file_path = event.src_path
            with open("coordinates.txt") as f:
                for line in f:
                    coords= line.strip().split(",")
                    if len(coords) == 2:  # проверка на корректность данных
                        write_to_db(coords)




event_handler = FileHandler()
observer = Observer()
observer.schedule(event_handler, path='coordinates.txt', recursive=False)
observer.start()
try:
    while True:


        cur.execute("SELECT id, lon, lat FROM locations;")
        records = cur.fetchall()
        for record in records:
            id, lat, long = record
            lat += random.uniform(-0.001, 0.001)
            long += random.uniform(-0.001, 0.001)
            cur.execute("UPDATE locations SET lon=%s, lat=%s WHERE id=%s", (lat, long, id))

        cur.execute('SELECT * FROM locations')
        rows = cur.fetchall()
        for row in rows:
            print(row)

        time.sleep(5)
except KeyboardInterrupt:
    observer.stop()
observer.join()

conn.close()