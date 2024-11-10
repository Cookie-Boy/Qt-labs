#ifndef USERSERVICE_H
#define USERSERVICE_H


#include <QString>

class UserService
{
public:
    static UserService& instance();
    bool registerUser(const QString& email,
                      const QString& lastName,
                      const QString& firstName,
                      const QString& middleName,
                      short drivingExperience);
    bool authorizeUser(const QString &email);

private:
    UserService();
};

#endif // USERSERVICE_H
