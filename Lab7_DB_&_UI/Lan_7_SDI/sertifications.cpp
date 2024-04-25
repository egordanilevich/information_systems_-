#include "sertifications.h"
#include "ui_sertifications.h"
#include <QSqlQuery>
#include <QSqlRecord>

sertifications::sertifications(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sertifications)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3); // Количество столбцов
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "ID заявителя", "Дата выдачи"});

    if (databaseManager.openDatabase("my_database.db"))
    {
        QSqlQuery query = databaseManager.executeQuery("SELECT * FROM issued_certificates");
        int row = 0;
        while (query.next())
        {
            int id = query.value("id").toInt();
            int applicantId = query.value("applicant_id").toInt();
            QString issueDate = query.value("issue_date").toString();

            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(applicantId)));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(issueDate));

            ++row;
        }
    }
    else
    {
        qDebug() << "Failed to open the database";
    }

    databaseManager.closeDatabase();
}

sertifications::~sertifications()
{
    delete ui;
}
