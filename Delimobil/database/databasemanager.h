#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    bool openConnection();
    void closeConnection();
private:
    DatabaseManager();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
