#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QWidget>
#include <QString>
#include "employeedbutils.cpp"

namespace Ui
{
    class EmployeeInfo;
}

class EmployeeInfo : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeInfo(QWidget *parent = 0, QString id = "");
    ~EmployeeInfo();
    EmployeeDatabaseUtils empDBUtils;

protected:
   void mousePressEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   QPoint mousePoint;

private slots:
    void on_pushButton_clicked();

private:
    Ui::EmployeeInfo *ui;
    bool isMouseDown = false;
};

#endif // EMPLOYEEINFO_H
