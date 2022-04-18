#ifndef TECHUSED_H
#define TECHUSED_H

#include <QWidget>

namespace Ui {
class TechUsed;
}

class TechUsed : public QWidget
{
    Q_OBJECT

public:
    explicit TechUsed(QWidget *parent = 0);
    ~TechUsed();

protected:
   void mousePressEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   QPoint mousePoint;

private slots:
    void on_pushButton_clicked();

private:
    Ui::TechUsed *ui;

    bool isMouseDown = false;
};

#endif // TECHUSED_H
