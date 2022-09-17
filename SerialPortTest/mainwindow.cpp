#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Adding title to the widget
    QWidget::setWindowTitle("MicroMouse Serial Port Test");

    // Ports
    QList<QSerialPortInfo> ports = serial_port_info_.availablePorts();
    QList<QString> ports_str;
    for(const auto& p : ports)
    {
        ports_str.append(p.portName());
    }
    ui->comboBox_serialPort->addItems((ports_str));

    QList<qint32> baud_rates = serial_port_info_.standardBaudRates();
    QList<QString> baud_rates_str;
    for(const auto& bd : baud_rates)
    {
        baud_rates_str.append(QString::number(bd));
    }
    ui->comboBox_baudRate->addItems((baud_rates_str));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_openSerial_clicked()
{
    QString port_name = ui->comboBox_serialPort->currentText();
    serial_port_.setPortName(port_name);
    serial_port_.open(QIODevice::ReadWrite);

    QString port_status_str;

    if(!serial_port_.isOpen())
    {
//        ui->lineEdit_portStatus->setTextColor(Qt::red);
//        ui->lineEdit_portStatus->append("Serial port open error! Please check the connection!");
        port_status_str = "Port error!";
    }
    else
    {
        QString baud_rate_str = ui->comboBox_baudRate->currentText();
        serial_port_.setBaudRate(baud_rate_str.toInt());
        port_status_str = "Port opened!";
        connect(&serial_port_,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
    }
//    ui->lineEdit_portStatus->text(port_status_str);
}

void MainWindow::receiveMessage()
{
    QByteArray dataBA = serial_port_.readAll();
    QString data(dataBA);
    buffer_.append(data);
//    int index = buffer_.indexOf(code);
    if(buffer_.size()){
       QString message = buffer_;
       ui->textEdit_serialRead->setTextColor(Qt::blue); // Receieved message's color is blue.
       ui->textEdit_serialRead->append(message);
//       buffer.remove(0,index+codeSize);
    }
    buffer_.clear();

}
