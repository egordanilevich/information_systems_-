#include "databasemanager.h"
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
}

DatabaseManager::~DatabaseManager()
{
    closeDatabase();
}

bool DatabaseManager::openDatabase(const QString &databaseName)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databaseName);

    if (!database.open())
    {
        qDebug() << "Ошибка при открытии базы данных:" << database.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::closeDatabase()
{
    if (database.isOpen())
    {
        database.close();
    }
}

QSqlQuery DatabaseManager::executeQuery(const QString &queryString)
{
    QSqlQuery query(queryString);

    if (!query.isActive())
    {
        qDebug() << "Ошибка при выполнении запроса:" << query.lastError().text();
    }

    return query;
}
