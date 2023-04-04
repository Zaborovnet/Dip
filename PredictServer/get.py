import psycopg2
import os
import random
import time
import requests
import datetime


# получение последних созданных объектов
response = requests.get('http://localhost:5000/')
print(response.status_code)
print(response.text)
print(response.content)