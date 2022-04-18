#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QLabel>
#include <QTableView>
#include <QSqlDatabase>

class DatabaseUtils
{
    public:

    QSqlDatabase db = QSqlDatabase::database("firstConn");

    bool connectToDB(QString dbName)
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName(dbName);
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("");

        if(db.open())
        {
            qDebug() << ("Connected to database");
            return true;
        }
        else
        {
            qDebug() << ("Failed to open the database");
            return false;
        }
    }

    void closeDBConnection()
    {

        if(db.isValid())
        {
            qDebug() <<"Connection Valid";
            db.removeDatabase("firstConn");
            db.close();
        }
        else
        {
            qDebug() <<"Connection Invalid";
        }       

    }

    QSqlQueryModel* getDepartmentList()
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT DISTINCT(department) FROM company");

        if(qry->exec())
        {
            model->setQuery(*qry);
            qDebug() << "Sucesss";
        }
        else
        {
            qDebug() << "Failed";
        }

        return model;
    }

    QSqlQueryModel* getDesignationList(QComboBox* dept)
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT designation FROM company WHERE department='" + dept->currentText() + "';");

        if(qry->exec())
        {
            model->setQuery(*qry);
            qDebug() << "Sucesss";           
        }
        else
        {
            qDebug() << "Failed";
        }

        return model;
    }

    QString getLastID()
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT MAX(Employee_ID) FROM employee");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt() + 1;

        return QString::number(lastID);
    }

    QString getTotalEmployee()
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT COUNT(Employee_ID) FROM employee");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt();

        return QString::number(lastID);
    }

    QString getTotalDept()
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT COUNT(DISTINCT(department)) FROM company");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt();

        return QString::number(lastID);
    }

    QString getTotalDesign()
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT COUNT(DISTINCT(designation)) FROM company");
        qry->exec();
        qry->next();

        int lastID = qry->value(0).toInt();

        return QString::number(lastID);
    }


    QString getEmployeeID(QString dept, QString design)
    {
        return dept + "/" + design + "/" + getLastID();
    }

    QString getDesignationShortName(QComboBox* design)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT design_short FROM company WHERE designation='" + design->currentText() + "';");
        qry->exec();
        qry->next();

        QString x = qry->value(0).toString();

        return x;
    }

    QString getDepartmentShortName(QComboBox* dept)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT dept_short FROM company WHERE department='" + dept->currentText() + "';");
        qry->exec();
        qry->next();

        QString x = qry->value(0).toString();

        return x;
    }

    int getSalary(QComboBox* dept, QComboBox* design)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT salary FROM company WHERE department='" + dept->currentText() + "' AND designation='" +design->currentText() + "';");
        qry->exec();
        qry->next();

        int x = qry->value(0).toInt();

        return x;
    }

    void setEmployeeDetails(QTableView* tableView)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            querModel->setQuery("SELECT id, name, department, designation, phone, email FROM employee;");
            tableView->setModel(querModel);
        }
    }

    void searchEmployeeDetails(QTableView* tableView, QString searchText)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            querModel->setQuery("SELECT id, name, department, designation, phone, email FROM employee WHERE name LIKE '" + searchText + "%' OR id LIKE '" + searchText +"%';");
            tableView->setModel(querModel);
        }
    }

    void setEmployeeUpdateDetails(QTableView* tableView)
    {
        if(db.isOpen())
        {
            QSqlQueryModel *querModel = new QSqlQueryModel();
            querModel->setQuery("SELECT id, name, phone FROM employee;");
            tableView->setModel(querModel);
        }
    }

    QSqlQuery* showEmployeeDetailsToLineEdit(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT * FROM employee WHERE id='" + id + "';");
        qry->exec();
        qry->next();  

        return qry;
    }

    void deleteEmployeeRecord(QString id)
    {
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("DELETE  FROM employee WHERE id='" + id + "';");

        qry->exec();
    }


};
