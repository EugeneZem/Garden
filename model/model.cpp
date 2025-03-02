#include "model.h"

DBPlants::DBPlants(QObject *parent)
    : QObject{parent}
{

//    dataBase = new QSqlDatabase();


}

DBPlants::~DBPlants()
{

}

bool DBPlants::ConnectToDataBase(std::vector<std::string> dataForConnect)
{
    QSqlDatabase dataBase_ = QSqlDatabase::addDatabase("QPSQL");
    dataBase_.setHostName("localhost");
    dataBase_.setDatabaseName("Spider");
    dataBase_.setUserName("postgres");
    dataBase_.setPassword("392260");

    qDebug() << dataBase_.databaseName();
    return dataBase_.open();
}

QString DBPlants::databaseName() const
{
return "dataBase_.databaseName()";
}



std::vector<std::string> DBPlants::ConnectionInfo()
{
    std::vector<std::string> conectedData;

    conectedData.clear();
    conectedData.resize(5);
    conectedData[hostName]  = "localhost";
    conectedData[dbName]    = "Spider";
    conectedData[login]     = "postgres";
    conectedData[pass]      = "392260";
    conectedData[port]      = "5432";

    return conectedData;
}
