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
    long getFreeId();
    bool saveUser(const User &user);
private:
    UserRepository();
};

#endif // USERREPOSITORY_H
