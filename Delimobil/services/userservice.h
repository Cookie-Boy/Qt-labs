#ifndef USERSERVICE_H
#define USERSERVICE_H


#include <QString>
#include "../repositories/userrepository.h"
#include "../models/authorizeduser.h"

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
    UserRepository& userRepository;
    AuthorizedUser& authorizedUser;
    UserService(UserRepository userRepository);
    UserService();
};

#endif // USERSERVICE_H
