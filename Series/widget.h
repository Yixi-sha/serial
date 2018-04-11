#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QComboBox>
#include <QLabel>
#include <QFont>
#include <QStackedLayout>
#include <QPlainTextEdit>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QMutex>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QSpinBox>
#include "MySeries/seriinfo.h"
#include "MySeries/threadseries.h"
#include "btn/openclosebtn.h"


class Widget : public QWidget
{
    Q_OBJECT

    bool m_ReceiceHEX;
    bool m_SendHEX;

    seriinfo m_seriInfo;
    threadSeries m_threadSeries;

    QPalette palette;
    QFont font;
    QTimer m_timer;
    QSerialPortInfo m_portInfo;


    OpenCloseBtn openClose_Btn;

    QPushButton series_Btn;
    QPushButton PID_Btn;

    QLabel setPort_Lble;
    QComboBox setPort_Cbox;

    QLabel baudRate_Lble;
    QComboBox baudRate_Cbox;

    QLabel dataBits_Lble;
    QComboBox dataBits_Cbox;

    QLabel stopBits_Lble;
    QComboBox stopBits_Cbox;

    QLabel setParity_Lble;
    QComboBox setParity_Cbox;

    QStackedLayout stackLayout;

    QLabel reseive_Lbel;
    QPlainTextEdit reseiveEdit;
    QLabel send_Lbel;
    QPlainTextEdit sendEdit;

    QPushButton reseiveTra_btn;
    QPushButton reseiveClear_btn;

    QPushButton sendTra_btn;
    QPushButton sendClear_btn;
    QPushButton send_btn;


    QSpinBox first1P_SpB;
    QSpinBox first1I_SpB;
    QSpinBox first1D_SpB;

    QSpinBox first2P_SpB;
    QSpinBox first2I_SpB;
    QSpinBox first2D_SpB;

    QSpinBox first3P_SpB;
    QSpinBox first3I_SpB;
    QSpinBox first3D_SpB;


    void initSerierPort();

    bool initSeriesPgae();
    bool initPIDUI();
    bool initUI();


    Widget(QWidget *parent = 0);
    bool twoConstrut();

public slots:
    void OnTimeout();
    void onOpenClose();
    void OnsendBtn();
    void OnreseiveClear();
    void OnsendClear();
    void OnchangeReceive();
    void OnchangeSend();
    void openCloseUI(bool open,bool success);
    void updateReceiveUI(QString text);
    void OnreadyRead();

    void Onseries_Btn();
    void OnPID_Btn();
public:
    static Widget* newWidget();

    ~Widget();
};

#endif // WIDGET_H
