#ifndef THREADSERIES_H
#define THREADSERIES_H


#include <QThread>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "seriinfo.h"

class threadSeries : public QObject
{
    Q_OBJECT
    QThread m_thread;
public:
    QSerialPort m_series;
    explicit threadSeries(QObject *parent = nullptr);
    ~threadSeries();

    void start();
    void terminate();
    void exit(int c);
signals:
    void OpenCloseUISIG(bool open,bool success);
    void openCloseSIG(seriinfo info,bool open);
    void SendDateSIG(QByteArray date);
    void SendDateChangSIG(QString buf,bool m_SendHEX);
    void ReceiveDateChangSIG(QByteArray buf,bool m_ReceiceHEX);
    void ReceiveupdateUISIG(QString str);
public slots:
    void openCloseSeries(seriinfo info,bool open);
    void SendDate(QByteArray date);
    void SendDateChang(QString buf,bool m_SendHEX);
    void ReceiveDateChang(QByteArray buf,bool m_ReceiceHEX);

};

#endif // THREADSERIES_H
