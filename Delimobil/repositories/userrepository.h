#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

#include "../models/user.h"

class UserRepository
{
public:
    static UserRepository& instance();
    bool saveUser(const User *user);
    User* findUserByEmail(const QString& email);
    bool updateUser(const QString& id, const User& newUser);
private:
    long getFreeId();
    UserRepository();
};

#endif // USERREPOSITORY_H
