#ifndef SERIINFO_H
#define SERIINFO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMetaType>

class seriinfo : public QObject
{
    Q_OBJECT

    int m_baudrate;
    QSerialPort::DataBits m_dataBits;
    QSerialPort::FlowControl m_flowControl;
    QSerialPort::Parity m_parity;
    QSerialPort::StopBits m_stopBits;
    QSerialPortInfo m_port;

public:
    explicit seriinfo(QObject *parent = nullptr);
    seriinfo(const seriinfo& obj);

    void set_baudRate( int baudrate);
    void set_dataBits( QSerialPort::DataBits dataBits);
    void set_flowControl( QSerialPort::FlowControl flowControl);
    void set_parity( QSerialPort::Parity parity);
    void set_stopBits( QSerialPort::StopBits stopBits);
    void set_port( QSerialPortInfo port);

    int get_baudRate(void) const;
    QSerialPort::DataBits get_dataBits( void) const;
    QSerialPort::FlowControl get_flowControl( void) const;
    QSerialPort::Parity get_parity( void) const;
    QSerialPort::StopBits get_stopBits( void) const;
    QSerialPortInfo get_port( void) const;


signals:

public slots:
};

#endif // SERIINFO_H
