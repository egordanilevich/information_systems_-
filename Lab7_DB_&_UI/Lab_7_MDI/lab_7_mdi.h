#ifndef LAB_7_MDI_H
#define LAB_7_MDI_H

#include <QMainWindow>
#include <QProcess>
#include <QCoreApplication>
#include "clients.h"
#include "protocols.h"
#include "sertifications.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lab_7_MDI; }
QT_END_NAMESPACE

class Lab_7_MDI : public QMainWindow
{
    Q_OBJECT

public:
    Lab_7_MDI(QWidget *parent = nullptr);
    ~Lab_7_MDI();

private slots:
    void on_pushButton_clients_clicked();

    void on_pushButton_protocols_clicked();

    void on_pushButton_sertifications_clicked();

private:
    Ui::Lab_7_MDI *ui;

    QWidget *widget_clients;
    QWidget *widget_protocol;
    QWidget *widget_sertificate;
};
#endif // LAB_7_MDI_H
