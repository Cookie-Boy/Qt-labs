#include "userservice.h"
#include "../models/user.h"
#include "../repositories/userrepository.h"
#include "../models/authorizeduser.h"

#include <QString>

UserService::UserService() {

}

UserService& UserService::instance() {
    static UserService instance;
    return instance;
}

bool UserService::registerUser(const QString& email,
                               const QString& lastName,
                               const QString& firstName,
                               const QString& middleName,
                               short drivingExperience) {
    if (email.length() == 0 || lastName.length() == 0 || firstName.length() == 0 || middleName.length() == 0)
        return false;

    long id = UserRepository::instance().getFreeId();
    QDateTime registrationDate = QDateTime::currentDateTime();
    User newUser(id, firstName, lastName, middleName, email, registrationDate, drivingExperience);

    // Сохраняем пользователя через репозиторий
    if (!UserRepository::instance().saveUser(newUser)) {
        qDebug() << "Ошибка при регистрации пользователя!";
        return false;
    }
    qDebug() << "Пользователь успешно зарегистрирован!";
    AuthorizedUser::instance().setUser(newUser);
    return true;
}

bool UserService::authorizeUser(const QString& email) {
    User *user = UserRepository::instance().findUserByEmail(email);
    if (user == nullptr) {
        User user = User(email);
        AuthorizedUser::instance().setUser(user);
        return false;
    }
    AuthorizedUser::instance().setUser(*user);
    qDebug() << "Успешная авторизация";
    return true;
}
