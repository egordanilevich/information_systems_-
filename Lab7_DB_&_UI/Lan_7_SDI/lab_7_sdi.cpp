#include "lab_7_sdi.h"
#include "ui_lab_7_sdi.h"

Lab_7_SDI::Lab_7_SDI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab_7_SDI)
{
    ui->setupUi(this);
}

Lab_7_SDI::~Lab_7_SDI()
{
    delete ui;
}


void Lab_7_SDI::on_pushButton_clients_clicked() //клиенты
{
    clients* clients_wind = new clients();
    clients_wind->setWindowTitle("Заявители");
    clients_wind->show();
}


void Lab_7_SDI::on_pushButton_protocols_clicked() // протоколы
{
    protocols* protocols_wind = new protocols();
    protocols_wind->setWindowTitle("Протоколы");
    protocols_wind->show();
}


void Lab_7_SDI::on_pushButton_sertifications_clicked() // сертификаты
{
    sertifications* sertifications_wind = new sertifications();
    sertifications_wind->setWindowTitle("Сертификаты");
    sertifications_wind->show();
}

