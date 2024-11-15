#ifndef AUTHORIZEDUSER_H
#define AUTHORIZEDUSER_H

#include "user.h"
#include "car.h"

class AuthorizedUser
{
private:
    User user;
    Car* car;
    AuthorizedUser();

public:
    static AuthorizedUser& instance();
    void setUser(User& user);
    User& getUser();
    void setCar(Car* car);
    Car* getCar();

    // Удалим копирование и присваивание, чтобы соответствовать шаблону синглтона
    AuthorizedUser(const AuthorizedUser&) = delete;
    AuthorizedUser& operator=(const AuthorizedUser&) = delete;
};

#endif // AUTHORIZEDUSER_H
