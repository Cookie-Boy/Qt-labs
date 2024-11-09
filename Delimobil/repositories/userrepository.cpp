#include "userrepository.h"

UserRepository::UserRepository() {
}

UserRepository& UserRepository::instance() {
    static UserRepository instance;
    return instance;
}

long UserRepository::getFreeId() {
    QSqlQuery query;
    long freeId = 0;

    if (!query.exec("SELECT * FROM users")) {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
        return -1;
    }

    while (query.next()) {
        long id = static_cast<long>(query.value(0).toLongLong());
        if (id != freeId)
            return freeId;
        freeId++;
    }

    return freeId;
}

bool UserRepository::saveUser(const User& user) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (id, fullName, email, registrationDate, drivingExperience) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(QVariant::fromValue(static_cast<long>(user.getId())));
    query.addBindValue(user.getFullName());
    query.addBindValue(user.getEmail());
    query.addBindValue(user.getRegistrationDate());
    query.addBindValue(user.getDrivingExperience());

    if (!query.exec()) {
        qDebug() << "Ошибка при сохранении пользователя:" << query.lastError().text();
        return false;
    }

    return true;
}
