#include "lab_7_mdi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab_7_MDI w;
    w.show();
    return a.exec();
}
