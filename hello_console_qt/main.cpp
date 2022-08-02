#include <QCoreApplication>
#include <iostream>
#include <string>

#include <QTextStream>

void do_cpp()
{
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << ", nice to meet you.\n";
}

void do_qt()
{
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "What is your name? ";
    qout.flush();
    QString qname = qin.readLine();
    qout << "Hello " << qname << "\n";
    qout.flush();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do_qt();
//    do_cpp();

    return a.exec();
}
