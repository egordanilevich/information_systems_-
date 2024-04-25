#include "protocols.h"
#include "ui_protocols.h"
#include <QSqlQuery>
#include <QSqlRecord>

protocols::protocols(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::protocols)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3); // Количество столбцов
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "ID заявителя", "Дата испытания"});

    if (databaseManager.openDatabase("my_database.db"))
    {
        QSqlQuery query = databaseManager.executeQuery("SELECT * FROM test_protocols");
        int row = 0;
        while (query.next())
        {
            int id = query.value("id").toInt();
            int applicantId = query.value("applicant_id").toInt();
            QString testDate = query.value("test_date").toString();

            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(applicantId)));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(testDate));

            ++row;
        }
    }
    else
    {
        qDebug() << "Failed to open the database";
    }

    databaseManager.closeDatabase();
}

protocols::~protocols()
{
    delete ui;
}
