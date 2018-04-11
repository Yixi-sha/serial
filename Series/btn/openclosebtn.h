#ifndef OPENCLOSEBTN_H
#define OPENCLOSEBTN_H

#include <QPushButton>
#include <QImage>
#include <QPixmap>

class OpenCloseBtn : public QPushButton
{
    Q_OBJECT

    QImage m_image;
    QPixmap m_pixmap;
    bool m_open;

    void paintEvent(QPaintEvent* eve);
public:
    explicit OpenCloseBtn(QPushButton *parent = nullptr);


    bool isOpenPic();
    void setOpenPic(bool open);
    ~OpenCloseBtn();
signals:

public slots:
    void onPress();

};

#endif // OPENCLOSEBTN_H
