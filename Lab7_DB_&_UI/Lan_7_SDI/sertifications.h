#ifndef SERTIFICATIONS_H
#define SERTIFICATIONS_H

#include <QWidget>
#include "databasemanager.h"

namespace Ui {
class sertifications;
}

class sertifications : public QWidget
{
    Q_OBJECT

public:
    explicit sertifications(QWidget *parent = nullptr);
    ~sertifications();

private:
    Ui::sertifications *ui;
    DatabaseManager databaseManager;

};

#endif // SERTIFICATIONS_H
