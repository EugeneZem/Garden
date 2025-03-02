#include "model.h"

DBPlants::DBPlants(QObject *parent)
    : QObject{parent}
{
    dataBase_ = new QSqlDatabase();
    dataQuery_ = new QSqlQuery();
}

DBPlants::~DBPlants()
{
    delete dataBase_;
    delete dataQuery_;
}

void DBPlants::AddDataBase(QString driver, QString nameDB)
{
    *dataBase_ = QSqlDatabase::addDatabase(driver, nameDB);
    *dataQuery_ = QSqlQuery(*dataBase_);
}

bool DBPlants::ConnectToDataBase(std::vector<QString> data)
{
    dataBase_->setHostName(data[hostName]);
    dataBase_->setDatabaseName(data[dbName]);
    dataBase_->setUserName(data[login]);
    dataBase_->setPassword(data[pass]);
    dataBase_->setPort(data[port].toInt());

    return dataBase_->open();
}

QSqlError DBPlants::GetLastError() const
{
    return dataBase_->lastError();
}

QString DBPlants::databaseName() const
{
    return dataBase_->connectionName();
}

void DBPlants::DisconnectDataBase()
{

}

std::vector<QString> DBPlants::ConnectionInfo()
{
    std::vector<QString> conectedData;

    conectedData.resize(5);
    conectedData[hostName]  = "localhost";
    conectedData[dbName]    = "Spider";
    conectedData[login]     = "postgres";
    conectedData[pass]      = "392260";
    conectedData[port]      = "5432";

    return conectedData;
}
