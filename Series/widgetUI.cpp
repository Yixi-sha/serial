#include "widget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QColor>
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent,Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint)
{

}

bool Widget::initUI()
{
    bool ret = true;
    QVBoxLayout* VBox_0 = new QVBoxLayout();
    QHBoxLayout* HBox_0 = new QHBoxLayout();
    QVBoxLayout* VBox_1 = new QVBoxLayout();
    QHBoxLayout* HBox_1 = new QHBoxLayout();

    if(VBox_0 == NULL || HBox_0 == NULL || VBox_1 == NULL || HBox_1 == NULL)
    {
        ret = false;

        if(VBox_0 != NULL)
        {
            delete VBox_0;
        }
        if(HBox_0 != NULL)
        {
            delete VBox_0;
        }
        if(VBox_1 != NULL)
        {
            delete VBox_0;
        }
        if(HBox_1 != NULL)
        {
            delete VBox_0;
        }
    }

    if(ret)
    {



        setPort_Lble.setText("Select Port");
        VBox_0->addWidget(&setPort_Lble);
        VBox_0->addWidget(&setPort_Cbox);
        VBox_0->addSpacing(20);


        baudRate_Lble.setText("Set BaudRate");
        VBox_0->addWidget(&baudRate_Lble);
        baudRate_Cbox.addItem(QString::number(115200));
        baudRate_Cbox.addItem(QString::number(57600));
        baudRate_Cbox.addItem(QString::number(38400));
        baudRate_Cbox.addItem(QString::number(19200));
        baudRate_Cbox.addItem(QString::number(9600));
        baudRate_Cbox.addItem(QString::number(4800));
        baudRate_Cbox.addItem(QString::number(2400));
        baudRate_Cbox.addItem(QString::number(1200));
        VBox_0->addWidget(&baudRate_Cbox);
        VBox_0->addSpacing(20);

        dataBits_Lble.setText("Set DataBits");
        VBox_0->addWidget(&dataBits_Lble);
        dataBits_Cbox.addItem(QString("Data8"));
        dataBits_Cbox.addItem(QString("Data7"));
        dataBits_Cbox.addItem(QString("Data6"));
        dataBits_Cbox.addItem(QString("Data5"));
        VBox_0->addWidget(&dataBits_Cbox);
        VBox_0->addSpacing(20);

        stopBits_Lble.setText("Set stopBits");
        VBox_0->addWidget(&stopBits_Lble);
        stopBits_Cbox.addItem(QString("OneStop"));
        stopBits_Cbox.addItem(QString("OneAndHalfStop"));
        stopBits_Cbox.addItem(QString("TwoStop"));
        VBox_0->addWidget(&stopBits_Cbox);
        VBox_0->addSpacing(20);

        setParity_Lble.setText("Set Parity");
        VBox_0->addWidget(&setParity_Lble);
        setParity_Cbox.addItem(QString("NoParity"));
        setParity_Cbox.addItem(QString("EvenParity"));
        setParity_Cbox.addItem(QString("OddParity"));
        setParity_Cbox.addItem(QString("SpaceParity"));
        VBox_0->addWidget(&setParity_Cbox);
        VBox_0->addSpacing(20);


        openClose_Btn.setMinimumSize(100,100);
        VBox_0->addWidget(&openClose_Btn);
        VBox_0->addSpacing(60);



        /*************I`m cut-off rule ****************/
        series_Btn.setText("Series Helper");
        series_Btn.setMinimumSize(200,100);
        HBox_0->addWidget(&series_Btn);


        HBox_0->addSpacing(100);

        PID_Btn.setText("PID Helper");
        PID_Btn.setMinimumSize(200,100);
        HBox_0->addWidget(&PID_Btn);

        /*************I`m cut-off rule ****************/
        HBox_1->addLayout(VBox_0);
        HBox_1->addLayout(&stackLayout);

        VBox_1->addLayout(HBox_1);
        VBox_1->addLayout(HBox_0);

        this->setLayout(VBox_1);
    }




    font.setPixelSize(18);
    this->setFont(font);

    this->setStyleSheet("QPushButton{background-color : rgb(93, 190, 255);} \
                         QComboBox{background-color: rgb(93, 190, 255);}");

    palette.setColor(QPalette::Window,QColor(Qt::white));
    this->setPalette(palette);


    return ret;
}

bool  Widget::initSeriesPgae()
{
    bool ret = true;

    QVBoxLayout* VBox_0 = new QVBoxLayout();
    QVBoxLayout* VBox_1 = new QVBoxLayout();
    QHBoxLayout* HBox_0 = new QHBoxLayout();
    QWidget* first = new QWidget();

    if(VBox_0 == NULL || first == NULL || VBox_1 == NULL || HBox_0 == NULL )
    {
        ret = false;

        if(VBox_0 != NULL)
        {
            delete VBox_0;
        }
        if(VBox_1 != NULL)
        {
            delete VBox_1;
        }
        if(first != NULL)
        {
            delete VBox_0;
        }
    }

    if(ret)
    {
        reseive_Lbel.setText("Reseive Edit");
        VBox_0->addWidget(&reseive_Lbel);
        reseiveEdit.setReadOnly(true);
        reseiveEdit.setMinimumSize(500,350);
        VBox_0->addWidget(&reseiveEdit);
        VBox_0->addSpacing(50);

        send_Lbel.setText("Send Edit");
        VBox_0->addWidget(&send_Lbel);
        sendEdit.setMinimumSize(500,200);
        VBox_0->addWidget(&sendEdit);
        VBox_0->addSpacing(50);

        /*************I`m cut-off rule ****************/
        VBox_1->addSpacing(200);
        reseiveTra_btn.setText("Reseive Change \n to Hexadecimal");
        reseiveTra_btn.setMinimumSize(140,50);
        VBox_1->addWidget(&reseiveTra_btn);


        reseiveClear_btn.setText("Clear Reseive \n Edit");
        reseiveClear_btn.setMinimumSize(100,50);
        VBox_1->addWidget(&reseiveClear_btn);


        sendClear_btn.setText("Clear Send  \n Edit");
        sendClear_btn.setMinimumSize(100,50);
        VBox_1->addWidget(&sendClear_btn);

        sendTra_btn.setText("Send With \n  Hexadecimal");
        sendTra_btn.setMinimumSize(100,50);
        VBox_1->addWidget(&sendTra_btn);

        send_btn.setText("Send  \n Message ");
        send_btn.setMinimumSize(100,50);
        VBox_1->addWidget(&send_btn);

        /*************I`m cut-off rule ****************/
        HBox_0->addLayout(VBox_0);
        HBox_0->addLayout(VBox_1);

        first->setLayout(HBox_0);
        stackLayout.addWidget(first);
    }

    return ret;
}
bool Widget::initPIDUI()
{
    bool ret = true;

    QWidget* PID = new QWidget();
    QVBoxLayout* VBox_0 = new QVBoxLayout();
    QVBoxLayout* VBox_1 = new QVBoxLayout();
    QVBoxLayout* VBox_2 = new QVBoxLayout();
    QHBoxLayout* HBox_0 = new QHBoxLayout();


    if( PID == NULL || VBox_0 == NULL || VBox_1 == NULL || VBox_2 == NULL || HBox_0 == NULL)
    {
        ret = false;
        if(PID != NULL)
        {
            delete PID;
        }
        if(VBox_0 != NULL)
        {
            delete PID;
        }
        if(VBox_1 != NULL)
        {
            delete PID;
        }
        if(VBox_2 != NULL)
        {
            delete PID;
        }
        if(HBox_0 != NULL)
        {
            delete PID;
        }
    }
    if(ret)
    {
        VBox_0->addWidget(&first1P_SpB);
        VBox_0->addWidget(&first1I_SpB);
        VBox_0->addWidget(&first1D_SpB);

        VBox_1->addWidget(&first2P_SpB);
        VBox_1->addWidget(&first2I_SpB);
        VBox_1->addWidget(&first2D_SpB);

        VBox_2->addWidget(&first3P_SpB);
        VBox_2->addWidget(&first3I_SpB);
        VBox_2->addWidget(&first3D_SpB);

        HBox_0->addLayout(VBox_0);
        HBox_0->addLayout(VBox_1);
        HBox_0->addLayout(VBox_2);
        PID->setLayout(HBox_0);


        stackLayout.addWidget(PID);
    }


    return ret;

}


bool Widget::twoConstrut()
{
    bool ret = true;

    ret = ret && initSeriesPgae();
    ret = ret && initPIDUI();
    ret = ret && initUI();
    if(ret)
    {
        send_btn.setEnabled(false);
        m_ReceiceHEX = false;
        m_SendHEX = false;
        connect(&openClose_Btn,SIGNAL(clicked(bool)),this,SLOT(onOpenClose()));
        connect(&m_timer,SIGNAL(timeout()),this,SLOT(OnTimeout()));
        connect(&(m_threadSeries.m_series),SIGNAL(readyRead()),this,SLOT(OnreadyRead()));
        connect(&send_btn,SIGNAL(clicked(bool)),this,SLOT(OnsendBtn()));
        connect(&sendClear_btn,SIGNAL(clicked(bool)),this,SLOT(OnsendClear()));
        connect(&reseiveClear_btn,SIGNAL(clicked(bool)),this,SLOT(OnreseiveClear()));
        connect(&reseiveTra_btn,SIGNAL(clicked(bool)),this,SLOT(OnchangeReceive()));
        connect(&sendTra_btn,SIGNAL(clicked(bool)),this,SLOT(OnchangeSend()));
        connect(&m_threadSeries,SIGNAL(OpenCloseUISIG(bool,bool)),this,SLOT(openCloseUI(bool,bool)));
        connect(&m_threadSeries,SIGNAL(ReceiveupdateUISIG(QString)),this,SLOT(updateReceiveUI(QString)));
        connect(&series_Btn,SIGNAL(clicked(bool)),this,SLOT(Onseries_Btn()));
        connect(&PID_Btn,SIGNAL(clicked(bool)),this,SLOT(OnPID_Btn()));

        m_timer.start(100);
    }


    return ret;
}

Widget* Widget::newWidget()
{
    Widget* ret = new Widget();

    if(ret == NULL || (!ret->twoConstrut()))
    {
        if(ret != NULL)
        {
            delete ret;
        }

        ret = NULL;
    }
    return ret;

}



Widget::~Widget()
{

}
