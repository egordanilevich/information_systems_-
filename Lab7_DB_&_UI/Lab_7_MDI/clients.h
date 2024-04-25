#ifndef CLIENTS_H
#define CLIENTS_H

#include <QWidget>
#include "databasemanager.h"

namespace Ui {
class clients;
}

class clients : public QWidget
{
    Q_OBJECT

public:
    explicit clients(QWidget *parent = nullptr);
    ~clients();

private:
    Ui::clients *ui;
    DatabaseManager databaseManager;
};

#endif // CLIENTS_H
