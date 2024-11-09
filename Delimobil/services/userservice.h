#ifndef USERSERVICE_H
#define USERSERVICE_H


#include <QString>

class UserService
{
public:
    static UserService& instance();
    void registerUser(const QString& fullName, const QString& email, short drivingExperience);
private:
    UserService();
};

#endif // USERSERVICE_H
