#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QMainWindow>
#include "databaseutils.cpp"
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    DatabaseUtils dbUtils;

 protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint mousePoint;

private slots:
    void on_closeButton_clicked();

    void loadTotalData();

    void on_minimizeButton_clicked();

    void on_pushButton_clicked();

    void on_attendanceButton_clicked();

    void on_searchButton_clicked();

    void on_paymentButton_clicked();

    void on_attendance1_2_clicked();

    void on_addEmpButton_clicked();

    void on_updateEmpButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_empDept_currentIndexChanged(const QString &arg1);

    void on_deleteEmpButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_updateTableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_deleteTableView_doubleClicked(const QModelIndex &index);

    void on_searchTextBox_returnPressed();

    void on_pushButton_6_clicked();

    void selectedPushButton(QPushButton *button);

    void deselectedPushButton(QPushButton *button);

    void on_techButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_aboutButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    bool isMouseDown = false;
};

#endif // MAINWINDOW_H
