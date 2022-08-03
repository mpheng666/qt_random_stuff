#ifndef HELLOMOC_H
#define HELLOMOC_H

#include <QObject>
#include <QDebug>

class HelloMOC : public QObject
{
    Q_OBJECT
public:
    explicit HelloMOC(QObject *parent = nullptr);

signals:
    void close();

public slots:
    void doSomething();

};

#endif // HELLOMOC_H
