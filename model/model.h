#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};


class DBPlants : public QObject
{
    Q_OBJECT

public:
    explicit DBPlants(QObject *parent = nullptr);
    ~DBPlants();

    void AddDataBase(QString driver, QString nameDB);

    bool ConnectToDataBase(std::vector<QString> dataForConnect);

    QSqlError GetLastError() const;

    QString databaseName() const;

    void DisconnectDataBase();

    void RequestToDB(std::string request);

    std::vector<QString> ConnectionInfo();

private:
    QSqlDatabase* dataBase_;

    QSqlQuery* dataQuery_;

    std::vector<QString> dataConnection_;

};

#endif // MODEL_H
