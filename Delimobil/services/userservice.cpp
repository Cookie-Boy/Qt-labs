#include "userservice.h"
#include "../models/user.h"
#include "../repositories/userrepository.h"

#include <QString>

UserService::UserService() {

}

UserService& UserService::instance() {
    static UserService instance;
    return instance;
}

void UserService::registerUser(const QString& fullName, const QString& email, short drivingExperience) {
    long id = UserRepository::instance().getFreeId();
    QDateTime registrationDate = QDateTime::currentDateTime();
    User newUser(id, fullName, email, registrationDate, drivingExperience);

    // Сохраняем пользователя через репозиторий
    if (UserRepository::instance().saveUser(newUser)) {
        qDebug() << "Пользователь успешно зарегистрирован!";
    } else {
        qDebug() << "Ошибка при регистрации пользователя!";
    }
}

bool UserService::authorizeUser(const QString& email) {
    return UserRepository::instance().isUserExists(email);
}
