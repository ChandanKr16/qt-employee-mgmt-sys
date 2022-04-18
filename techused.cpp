#include "techused.h"
#include "ui_techused.h"
#include "mainwindow.h"

TechUsed::TechUsed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TechUsed)
{
    ui->setupUi(this);
}

TechUsed::~TechUsed()
{
    delete ui;
}

void TechUsed::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;
        mousePoint = event->globalPos();
    }
}

void TechUsed::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
}

void TechUsed::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint delta = event->globalPos() - mousePoint;
    if(isMouseDown == true)
        move(x() + delta.x(), y() + delta.y());
    else
        move(x()+delta.x(), y()+delta.y());
        mousePoint = event->globalPos();
}

void TechUsed::on_pushButton_clicked()
{
    this->close();

    MainWindow* mainWin = new MainWindow();
    mainWin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWin->show();
}
