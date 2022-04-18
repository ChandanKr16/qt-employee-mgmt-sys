#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>

class EmployeeDatabaseUtils
{
    public:

    QSqlDatabase empDB;

    bool connectToDB(QString dbName)
    {
        empDB = QSqlDatabase::addDatabase("QMYSQL");
        empDB.setDatabaseName(dbName);
        empDB.setHostName("localhost");
        empDB.setUserName("root");
        empDB.setPassword("");

        if(empDB.open())
        {
            qDebug() << ("Connected to employee database");
            return true;
        }
        else
        {
            qDebug() << ("Failed to open the employee database");
            return false;
        }
    }

    void closeDBConnection()
    {

        if(empDB.isValid())
        {
            empDB.close();
            empDB.removeDatabase(QSqlDatabase::defaultConnection);
        }
    }

    QSqlQuery* getData(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(empDB);     

        qry->prepare("SELECT * FROM employee WHERE id='" + id + "';");

        if(qry->exec())
        {
            qry->next();
            return qry;

           // label->setText(qry->value(1).toString());
            qDebug() << "Got the employee information from the database";
        }
        else
        {
            return NULL;
            qDebug() << "Failed";
        }


    }
};
