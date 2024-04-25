#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include <QWidget>
#include "databasemanager.h"

namespace Ui {
class protocols;
}

class protocols : public QWidget
{
    Q_OBJECT

public:
    explicit protocols(QWidget *parent = nullptr);
    ~protocols();

private:
    Ui::protocols *ui;
    DatabaseManager databaseManager;

};

#endif // PROTOCOLS_H
