#include "MySeries/threadseries.h"
#include <QDebug>

threadSeries::threadSeries(QObject *parent) : QObject(parent)
{
    m_thread.start();
    moveToThread(&m_thread);
    this->setParent(NULL);
    connect(this,SIGNAL(openCloseSIG(seriinfo,bool)),this,SLOT(openCloseSeries(seriinfo,bool)));
    connect(this,SIGNAL(SendDateSIG(QByteArray)),this,SLOT(SendDate(QByteArray)));
    connect(this,SIGNAL(SendDateChangSIG(QString,bool)),this,SLOT(SendDateChang(QString,bool)));
    connect(this,SIGNAL(ReceiveDateChangSIG(QByteArray,bool)),this,SLOT(ReceiveDateChang(QByteArray,bool)));
}
void threadSeries::openCloseSeries(seriinfo info,bool open)
{
        if(open)
        {
            m_series.setBaudRate(info.get_baudRate());
            m_series.setDataBits(info.get_dataBits());
            m_series.setFlowControl(info.get_flowControl());
            m_series.setParity(info.get_parity());
            m_series.setPort(info.get_port());
            m_series.setStopBits(info.get_stopBits());
            if(m_series.open(QIODevice::ReadWrite))
            {
                m_series.clear();
                emit OpenCloseUISIG(true,true);
            }
            else
            {
                emit OpenCloseUISIG(true,false);
            }
        }
        else
        {
            m_series.close();
            emit OpenCloseUISIG(false,true);
        }
}


void threadSeries::SendDate(QByteArray date)
{
    m_series.write(date);
}

void threadSeries::ReceiveDateChang(QByteArray buf,bool m_ReceiceHEX)
{
    QString text = "";
    if(m_ReceiceHEX)
    {
        QByteArray byte = buf.toHex();
        for(int i =0;i<byte.count();i++)
        {
            if(i%2 == 0)
            {
                text += " 0x";
            }
            text += byte[i];
        }
    }
    else
    {
        text = buf;
    }
    emit ReceiveupdateUISIG(text);
}

void threadSeries::SendDateChang(QString buf,bool m_SendHEX)
{
    QByteArray ret;
    ret = buf.toLatin1();
    if(m_SendHEX)
    {
        ret = ret.toHex();
    }
    emit SendDate(ret);
}

void threadSeries::start()
{
    m_thread.start();
}

void threadSeries::terminate()
{
    m_thread.terminate();
}

void threadSeries::exit(int c)
{
    m_thread.exit(c);
}

threadSeries::~threadSeries()
{
    m_thread.exit(0);
    m_thread.wait();
}
