#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <QObject>
#include <QSqlDatabase>
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

    bool ConnectToDataBase(std::vector<std::string> dataForConnect);

    QString databaseName() const;

    void DisconnectDataBase();

    void RequestToDB(std::string request);

    std::vector<std::string> ConnectionInfo();

private:


    std::vector<std::string> dataConnection_;

};

#endif // MODEL_H
