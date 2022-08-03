#include <QCoreApplication>
#include <QDebug>

#include "hellomoc.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HelloMOC test1;

    // connect the signal and the slot
    QObject::connect(&test1, &HelloMOC::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    test1.doSomething();

    auto i = a.exec();

    qInfo() << "Return value: " << i;

    return i;
}
