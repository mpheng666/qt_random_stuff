#include "hellomoc.h"

HelloMOC::HelloMOC(QObject *parent)
    : QObject{parent}
{

}

void HelloMOC::doSomething()
{
    qInfo() << "Do something! \n";
    emit close();
}
