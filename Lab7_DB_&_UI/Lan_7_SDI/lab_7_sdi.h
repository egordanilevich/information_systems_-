#ifndef LAB_7_SDI_H
#define LAB_7_SDI_H

#include <QMainWindow>
#include <QProcess>
#include <QCoreApplication>
#include "clients.h"
#include "protocols.h"
#include "sertifications.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lab_7_SDI; }
QT_END_NAMESPACE

class Lab_7_SDI : public QMainWindow
{
    Q_OBJECT

public:
    Lab_7_SDI(QWidget *parent = nullptr);
    ~Lab_7_SDI();

private slots:
    void on_pushButton_clients_clicked();

    void on_pushButton_protocols_clicked();

    void on_pushButton_sertifications_clicked();

private:
    Ui::Lab_7_SDI *ui;
};
#endif // LAB_7_SDI_H
