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

//    qDebug() << "Port state: ";
    if(serial_port_status_ == serialPortState::PORT_UNOPENED)
    {
        QString port_name = ui->comboBox_serialPort->currentText();
        QString baud_rate_str = ui->comboBox_baudRate->currentText();

        serial_port_.setPortName(port_name);
        serial_port_.setBaudRate(baud_rate_str.toInt());
        serial_port_.open(QIODevice::ReadWrite);

        if(serial_port_.isOpen())
        {
            serial_port_status_ = serialPortState::PORT_OPENED;
            ui->lineEdit_portStatus->setText("Port opened");
            ui->pushButton_openSerial->setText("Close Port");
            connect(&serial_port_,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
        }
    }
    else if(serial_port_status_ == serialPortState::PORT_OPENED)
    {
        serial_port_.close();
        if(!serial_port_.isOpen())
        {
            serial_port_status_ = serialPortState::PORT_UNOPENED;
            ui->lineEdit_portStatus->setText("Port closed");
            ui->pushButton_openSerial->setText("Open Port");
        }
    }
    else if(serial_port_status_ == serialPortState::PORT_ERROR)
    {

    }
    else
    {

    }



}

void MainWindow::receiveMessage()
{
    QByteArray dataBA = serial_port_.readAll();
    QString data(dataBA);
    buffer_.append(data);
    if(buffer_.size()){
       QString message = buffer_;
       ui->textEdit_serialRead->setTextColor(Qt::blue); // Receieved message's color is blue.
       ui->textEdit_serialRead->append(message);
    }
    buffer_.clear();

}

void MainWindow::on_pushButton_clearScreen_clicked()
{
    ui->textEdit_serialRead->clear();
}


void MainWindow::on_pushButton_baudRate_clicked()
{
    QString baud_rate_str = ui->comboBox_baudRate->currentText();
    serial_port_.setBaudRate(baud_rate_str.toInt());
}

