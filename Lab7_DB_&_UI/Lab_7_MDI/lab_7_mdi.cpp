#include "lab_7_mdi.h"
#include "ui_lab_7_mdi.h"

Lab_7_MDI::Lab_7_MDI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab_7_MDI)
{
    ui->setupUi(this);
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // Выполнение Python-скрипта для создания базы данных
//    QString pythonPath = "python"; // Укажите полный путь к интерпретатору Python, если не находится в PATH
//    QString scriptPath = "BD_gen.py";

//    QProcess process;
//    process.start(pythonPath, QStringList() << scriptPath);
//    process.waitForFinished();

    widget_clients = new clients();
    widget_protocol = new protocols;
    widget_sertificate = new sertifications;
}

Lab_7_MDI::~Lab_7_MDI()
{
    delete ui;
}


void Lab_7_MDI::on_pushButton_clients_clicked() // Заявители
{
    ui->mdiArea->addSubWindow(widget_clients);
    widget_clients->setWindowTitle("Заявители");
    widget_clients->show();
    ui->mdiArea->tileSubWindows();
}


void Lab_7_MDI::on_pushButton_protocols_clicked() // Протоколы
{
    ui->mdiArea->addSubWindow(widget_protocol);
    widget_protocol->setWindowTitle("Протоколы");
    widget_protocol->show();
    ui->mdiArea->tileSubWindows();
}


void Lab_7_MDI::on_pushButton_sertifications_clicked() // Скртификаты
{
    ui->mdiArea->addSubWindow(widget_sertificate);
    widget_sertificate->setWindowTitle("Сертификаты");
    widget_sertificate->show();
    ui->mdiArea->tileSubWindows();
}

