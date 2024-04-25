import sqlite3
import os

# Подключение к базе данных
conn = sqlite3.connect('my_database.db')
cursor = conn.cursor()

# Удаление всех таблиц, если они существуют
cursor.execute('''
    DROP TABLE IF EXISTS issued_certificates;
''')
cursor.execute('''
    DROP TABLE IF EXISTS test_protocols;
''')
cursor.execute('''
    DROP TABLE IF EXISTS applicants;
''')

# Создание таблицы 'applicants'
cursor.execute('''
    CREATE TABLE IF NOT EXISTS applicants (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        first_name TEXT,
        last_name TEXT,
        age INTEGER
    )
''')
# Добавление данных в таблицу 'applicants'
cursor.execute('''
    INSERT INTO applicants (first_name, last_name, age)
    VALUES ('Ivan', 'Ivanov', 30),
           ('Peter', 'Petrov', 25),
           ('Anna', 'Sidorova', 35)
''')

# Создание таблицы 'test_protocols'
cursor.execute('''
    CREATE TABLE IF NOT EXISTS test_protocols (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        applicant_id INTEGER,
        test_date DATE,
        FOREIGN KEY (applicant_id) REFERENCES applicants (id)
    )
''')
# Добавление данных в таблицу 'test_protocols'
cursor.execute('''
    INSERT INTO test_protocols (applicant_id, test_date)
    VALUES (1, '2023-01-15'),
           (2, '2023-02-20'),
           (3, '2023-03-25')
''')

# Создание таблицы 'issued_certificates'
cursor.execute('''
    CREATE TABLE IF NOT EXISTS issued_certificates (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        applicant_id INTEGER,
        issue_date DATE,
        FOREIGN KEY (applicant_id) REFERENCES applicants (id)
    )
''')
# Добавление данных в таблицу 'issued_certificates'
cursor.execute('''
    INSERT INTO issued_certificates (applicant_id, issue_date)
    VALUES (1, '2023-01-20'),
           (2, '2023-02-25'),
           (3, '2023-03-30')
''')

# Сохранение изменений и закрытие соединения с базой данных
conn.commit()
conn.close()
