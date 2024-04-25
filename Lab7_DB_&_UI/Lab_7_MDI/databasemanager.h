#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    bool openDatabase(const QString &databaseName);
    void closeDatabase();

    QSqlQuery executeQuery(const QString &queryString);

private:
    QSqlDatabase database;
};

#endif // DATABASEMANAGER_H
