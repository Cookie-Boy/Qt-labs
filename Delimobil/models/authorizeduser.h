#ifndef AUTHORIZEDUSER_H
#define AUTHORIZEDUSER_H

#include "user.h"

class AuthorizedUser
{
private:
    User user;
    AuthorizedUser();

public:
    static AuthorizedUser& instance();
    void setUser(User& user);
    User& getUser();

    // Удалим копирование и присваивание, чтобы соответствовать шаблону синглтона
    AuthorizedUser(const AuthorizedUser&) = delete;
    AuthorizedUser& operator=(const AuthorizedUser&) = delete;
};

#endif // AUTHORIZEDUSER_H
