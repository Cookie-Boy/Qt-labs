#include "userservice.h"
#include "../models/user.h"

#include <QString>

UserService::UserService() : userRepository(UserRepository::instance()),
    authorizedUser(AuthorizedUser::instance()) { }

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

    QDateTime registrationDate = QDateTime::currentDateTime();
    User *newUser = new User(firstName, lastName, middleName, email, registrationDate, drivingExperience, "User");

    // Сохраняем пользователя через репозиторий
    if (!userRepository.saveUser(newUser)) {
        qDebug() << "Ошибка при регистрации пользователя!";
        return false;
    }
    qDebug() << "Пользователь успешно зарегистрирован!";
    authorizedUser.setUser(newUser);
    return true;
}

bool UserService::authorizeUser(const QString& email) {
    User *user = userRepository.findUserByEmail(email);
    if (user == nullptr) {
        User *user = new User(email);
        authorizedUser.setUser(user);
        return false;
    }
    authorizedUser.setUser(user);
    qDebug() << "Успешная авторизация";
    return true;
}
