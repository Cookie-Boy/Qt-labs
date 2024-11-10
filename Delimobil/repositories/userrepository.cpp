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
    query.prepare("INSERT INTO users (id, firstName, lastName, middleName, email, registrationDate, drivingExperience) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(QVariant::fromValue(static_cast<long>(user.getId())));
    query.addBindValue(user.getFirstName());
    query.addBindValue(user.getLastName());
    query.addBindValue(user.getMiddleName());
    query.addBindValue(user.getEmail());
    query.addBindValue(user.getRegistrationDate());
    query.addBindValue(user.getDrivingExperience());

    if (!query.exec()) {
        qDebug() << "Ошибка при сохранении пользователя:" << query.lastError().text();
        return false;
    }

    return true;
}

User* UserRepository::findUserByEmail(const QString& email) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Ошибка при выполнении запроса:" << query.lastError().text();
        return nullptr; // если запрос не выполнен
    }

    if (query.next()) {
        long id = static_cast<long>(query.value("id").toLongLong());
        QString firstName = query.value("firstName").toString();
        QString lastName = query.value("lastName").toString();
        QString middleName = query.value("middleName").toString();
        QString email = query.value("email").toString();
        QDateTime registrationDate = query.value("registrationDate").toDateTime();
        short drivingExperience = static_cast<short>(query.value("drivingExperience").toInt());

        return new User(id, firstName, lastName, middleName, email, registrationDate, drivingExperience);
        }

    return nullptr; // if user not found
}
