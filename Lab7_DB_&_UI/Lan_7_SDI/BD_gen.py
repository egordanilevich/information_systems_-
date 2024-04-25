# This Python file uses the following encoding: utf-8

# if __name__ == "__main__":
#     pass

import sqlite3

# Подключение к базе данных
conn = sqlite3.connect('my_database.db')
cursor = conn.cursor()

# Создание таблицы 'заявители'
cursor.execute('''
    CREATE TABLE IF NOT EXISTS заявители (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        имя TEXT,
        фамилия TEXT,
        возраст INTEGER
    )
''')

# Добавление данных в таблицу 'заявители'
cursor.execute('''
    INSERT INTO заявители (имя, фамилия, возраст)
    VALUES ('Иван', 'Иванов', 30),
           ('Петр', 'Петров', 25),
           ('Анна', 'Сидорова', 35)
''')

# Создание таблицы 'протоколы_испытваний'
cursor.execute('''
    CREATE TABLE IF NOT EXISTS протоколы_испытваний (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        id_заявителя INTEGER,
        дата_испытания DATE,
        FOREIGN KEY (id_заявителя) REFERENCES заявители (id)
    )
''')

# Добавление данных в таблицу 'протоколы_испытваний'
cursor.execute('''
    INSERT INTO протоколы_испытваний (id_заявителя, дата_испытания)
    VALUES (1, '2023-01-15'),
           (2, '2023-02-20'),
           (3, '2023-03-25')
''')

# Создание таблицы 'выданные_сертефикаты'
cursor.execute('''
    CREATE TABLE IF NOT EXISTS выданные_сертефикаты (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        id_заявителя INTEGER,
        дата_выдачи DATE,
        FOREIGN KEY (id_заявителя) REFERENCES заявители (id)
    )
''')

# Добавление данных в таблицу 'выданные_сертефикаты'
cursor.execute('''
    INSERT INTO выданные_сертефикаты (id_заявителя, дата_выдачи)
    VALUES (1, '2023-01-20'),
           (2, '2023-02-25'),
           (3, '2023-03-30')
''')

# Сохранение изменений и закрытие соединения с базой данных
conn.commit()
conn.close()
