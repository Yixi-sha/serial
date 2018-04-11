#include "seriinfo.h"
#include <QSerialPort>

seriinfo::seriinfo(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<seriinfo>("seriinfo");//注册PVCI_CAN_OBJ类型
}

seriinfo::seriinfo(const seriinfo& obj)
{
    this->m_baudrate = obj.get_baudRate();
    this->m_dataBits = obj.get_dataBits();
    this->m_flowControl = obj.get_flowControl();
    this->m_parity = obj.get_parity();
    this->m_stopBits = obj.get_stopBits();
    this->m_port = obj.get_port();
}

void seriinfo::set_baudRate( int baudrate)
{
    m_baudrate = baudrate;
}

void seriinfo::set_port(QSerialPortInfo port)
{
    m_port = port;
}

QSerialPortInfo seriinfo::get_port(void) const
{
    return m_port;
}


void seriinfo::set_dataBits(QSerialPort::DataBits dataBits)
{
    m_dataBits = dataBits;
}

void seriinfo::set_flowControl(QSerialPort::FlowControl flowControl)
{
    m_flowControl = flowControl;
}

void seriinfo::set_parity(QSerialPort::Parity parity)
{
    m_parity = parity;
}

void seriinfo::set_stopBits(QSerialPort::StopBits stopBits)
{
    m_stopBits = stopBits;
}

int seriinfo::get_baudRate(void) const
{
    return m_baudrate;
}

QSerialPort::DataBits seriinfo::get_dataBits(void) const
{
    return m_dataBits;
}

QSerialPort::FlowControl seriinfo::get_flowControl(void) const
{
    return m_flowControl;
}

QSerialPort::Parity seriinfo::get_parity(void) const
{
    return m_parity;
}

QSerialPort::StopBits seriinfo::get_stopBits(void) const
{
    return m_stopBits;
}
