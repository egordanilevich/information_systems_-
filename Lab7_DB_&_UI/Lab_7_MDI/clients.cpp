#include "clients.h"
#include "ui_clients.h"

clients::clients(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clients)
{
    ui->setupUi(this);

    if (databaseManager.openDatabase("my_database.db"))
    {
        QSqlQuery query = databaseManager.executeQuery("SELECT * FROM applicants");

        QSqlRecord record = query.record();
        int columnCount = record.count();
        ui->tableWidget->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(record.fieldName(col));
            ui->tableWidget->setHorizontalHeaderItem(col, headerItem);
        }

        int rowCount = 0;

        while (query.next()) {
            ui->tableWidget->insertRow(rowCount);

            for (int col = 0; col < columnCount; ++col) {
                QString value = query.value(col).toString();
                ui->tableWidget->setItem(rowCount, col, new QTableWidgetItem(value));
            }

            rowCount++;
        }

        databaseManager.closeDatabase();
    }
    else
    {
        qDebug() << "Failed to open the database";
    }
}

clients::~clients()
{
    delete ui;
}
