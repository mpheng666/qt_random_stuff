#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum class serialPortState
    {
        PORT_UNOPENED,
        PORT_OPENED,
        PORT_ERROR
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_openSerial_clicked();
    void receiveMessage();

    void on_pushButton_clearScreen_clicked();

    void on_pushButton_baudRate_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial_port_;
    QSerialPortInfo serial_port_info_;
    QString buffer_;
    serialPortState serial_port_status_ = serialPortState::PORT_UNOPENED;

};
#endif // MAINWINDOW_H
