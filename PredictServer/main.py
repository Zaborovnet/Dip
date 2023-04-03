from flask import Flask, jsonify, request
from psycopg2 import connect, sql

app = Flask(__name__)

# настройки подключения к БД
db_settings = {
    \'dbname\': \'targets\',
    \'user\': \'postgres\',
    \'host\': \'localhost\',
    \'password\': \'password\'
}