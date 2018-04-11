#include "widget.h"
#include <QList>
#include <QMessageBox>
#include <QTextStream>
#include <QTextCursor>



void Widget::OnTimeout()
{
    m_timer.stop();
    QString current = setPort_Cbox.currentText();
    setPort_Cbox.clear();
    setPort_Cbox.addItem(current);
    QList<QSerialPortInfo> info_List = QSerialPortInfo::availablePorts();
    for(int i =0;i<info_List.count();i++)
    {
        if(current !=info_List[i].portName())
        {
            setPort_Cbox.addItem(info_List[i].portName());
        }

    }

    m_timer.start(1000);
}

void Widget::initSerierPort()
{

    m_seriInfo.set_port(QSerialPortInfo(setPort_Cbox.currentText()));
    m_seriInfo.set_baudRate(baudRate_Cbox.currentText().toInt());

    if(dataBits_Cbox.currentText() == QString("Data8"))
    {
        m_seriInfo.set_dataBits(QSerialPort::Data8);
    }
    else if(dataBits_Cbox.currentText() == QString("Data7"))
    {
        m_seriInfo.set_dataBits(QSerialPort::Data7);
    }
    else if(dataBits_Cbox.currentText() == QString("Data6"))
    {
        m_seriInfo.set_dataBits(QSerialPort::Data6);
    }
    else if(dataBits_Cbox.currentText() == QString("Data5"))
    {
        m_seriInfo.set_dataBits(QSerialPort::Data5);
    }

    if(stopBits_Cbox.currentText() == QString("OneStop"))
    {
        m_seriInfo.set_stopBits(QSerialPort::OneStop);
    }
    else if(dataBits_Cbox.currentText() == QString("OneAndHalfStop"))
    {
        m_seriInfo.set_stopBits(QSerialPort::OneAndHalfStop);
    }
    else if(dataBits_Cbox.currentText() == QString("TwoStop"))
    {
        m_seriInfo.set_stopBits(QSerialPort::TwoStop);
    }

    if(setParity_Cbox.currentText() == QString("NoParity"))
    {
        m_seriInfo.set_parity(QSerialPort::NoParity);
    }
    else if(dataBits_Cbox.currentText() == QString("EvenParity"))
    {
        m_seriInfo.set_parity(QSerialPort::EvenParity);
    }
    else if(dataBits_Cbox.currentText() == QString("OddParity"))
    {
        m_seriInfo.set_parity(QSerialPort::OddParity);
    }
    else if(dataBits_Cbox.currentText() == QString("SpaceParity"))
    {
        m_seriInfo.set_parity(QSerialPort::SpaceParity);
    }
    m_seriInfo.set_flowControl(QSerialPort::NoFlowControl);
}



void Widget::openCloseUI(bool open,bool success)
{
    if(open)
    {
        if(success)
        {
            send_btn.setEnabled(true);
            openClose_Btn.setOpenPic(false);
        }
        else
        {
            openClose_Btn.setOpenPic(true);
            QMessageBox mes(this);
            mes.setWindowTitle("open series fail!!!");
            mes.setText("open series fail!!!");
            mes.addButton(QMessageBox::Ok);
            mes.setIcon(QMessageBox::Warning);
            mes.exec();
        }
    }
    else
    {
        if(success)
        {
            send_btn.setEnabled(false);
            openClose_Btn.setOpenPic(true);
        }
        else
        {
            QMessageBox mes(this);
            mes.setWindowTitle("ERROR!!!");
            mes.setText("ERROR fail!!!");
            mes.addButton(QMessageBox::Ok);
            mes.setIcon(QMessageBox::Warning);
            mes.exec();
            send_btn.setEnabled(false);
            openClose_Btn.setOpenPic(true);
        }
    }
}
void Widget::onOpenClose()
{
    if(openClose_Btn.isOpenPic())
    {
        emit m_threadSeries.openCloseSIG(m_seriInfo,false);
    }
    else
    {
        initSerierPort();
        emit m_threadSeries.openCloseSIG(m_seriInfo,true);

    }
}
void Widget::OnchangeReceive()
{
    if(!m_ReceiceHEX)
    {
        m_ReceiceHEX = true;
        reseiveTra_btn.setText("Reseive Change \n to decimal");
    }
    else
    {
        m_ReceiceHEX = false;
        reseiveTra_btn.setText("Reseive Change \n to Hexadecimal");
    }
}


void Widget::OnreadyRead()
{
    emit m_threadSeries.ReceiveDateChangSIG(m_threadSeries.m_series.readAll(),m_ReceiceHEX);
}
void Widget::updateReceiveUI(QString text)
{
    reseiveEdit.insertPlainText(text);
    QTextCursor cursor=reseiveEdit.textCursor();
    cursor.movePosition(QTextCursor::End);
    reseiveEdit.setTextCursor(cursor);
}
void Widget::OnchangeSend()
{
    if(!m_SendHEX)
    {
        m_SendHEX = true;
        sendTra_btn.setText("Send With \n  decimal");
    }
    else
    {
        m_SendHEX = false;
        sendTra_btn.setText("Send With \n  Hexadecimal");
    }
}

void Widget::OnsendBtn()
{
      emit m_threadSeries.SendDateChangSIG(sendEdit.toPlainText(), m_SendHEX);
}

void Widget::OnreseiveClear()
{
    reseiveEdit.clear();
}
void Widget::OnsendClear()
{
    sendEdit.clear();
}

void Widget::Onseries_Btn()
{
    emit m_threadSeries.openCloseSIG(m_seriInfo,false);
     stackLayout.setCurrentIndex(0);
}
void Widget::OnPID_Btn()
{
    emit m_threadSeries.openCloseSIG(m_seriInfo,false);
    stackLayout.setCurrentIndex(1);
}
