#include "lab_7_sdi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab_7_SDI w;
    w.show();
    return a.exec();
}
