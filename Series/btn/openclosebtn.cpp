#include "openclosebtn.h"
#include <QPainter>
#include <QPaintEvent>

OpenCloseBtn::OpenCloseBtn(QPushButton *parent) : QPushButton(parent) , m_image(":/res/pic/open.jpg")
{

    m_pixmap = QPixmap::fromImage(m_image);
    m_open = true;
    connect(this,SIGNAL(clicked()),this,SLOT(onPress()));
}

void OpenCloseBtn::paintEvent(QPaintEvent* eve)
{
     if(!m_pixmap.isNull())
     {
         QPainter Painter;

         Painter.begin(this);
         Painter.drawPixmap(eve->rect(),m_pixmap);
         Painter.end();
     }
}

void OpenCloseBtn::onPress()
{
    m_open = !m_open;
    if(m_open)
    {
        m_image = QImage(":/res/pic/open.jpg");
        m_pixmap = QPixmap::fromImage(m_image);     
    }
    else
    {
        m_image = QImage(":/res/pic/close.jpg");
        m_pixmap = QPixmap::fromImage(m_image);
    }
    update();
}




bool OpenCloseBtn::isOpenPic()
{
    return m_open;
}
void OpenCloseBtn::setOpenPic(bool open)
{
    m_open = !open;
    onPress();
}

OpenCloseBtn::~OpenCloseBtn()
{

}
