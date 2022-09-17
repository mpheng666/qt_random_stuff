#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_openSerial_clicked();
    void receiveMessage();

private:
    Ui::MainWindow *ui;
    QSerialPort serial_port_;
    QSerialPortInfo serial_port_info_;
    QString buffer_;
    QString code_;
    int code_size_;
};
#endif // MAINWINDOW_H
