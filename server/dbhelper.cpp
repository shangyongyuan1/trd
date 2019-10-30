#include "dbhelper.h"

DBHelper* DBHelper::instance = nullptr;

DBHelper* DBHelper::getInstance()
{
    if(instance == nullptr){
        instance = new DBHelper();
    }
    return instance;
}

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

}

void DBHelper::createConn()
{

    db.setDatabaseName("user.db");
    db.open();
}
void DBHelper::destoryConn()
{
    db.close();
    db.removeDatabase("user.db");
}
