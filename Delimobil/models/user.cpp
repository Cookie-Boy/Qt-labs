#include "User.h"

User::User(long id, const QString& firstName, const QString& lastName, const QString& middleName,
           const QString& email, const QDateTime& registrationDate, short drivingExperience, QString role)
    : id(id), firstName(firstName), lastName(lastName), middleName(middleName), email(email),
      registrationDate(registrationDate), drivingExperience(drivingExperience), role(role) {
}

User::User(const QString& firstName, const QString& lastName, const QString& middleName,
           const QString& email, const QDateTime& registrationDate, short drivingExperience, QString role)
    : firstName(firstName), lastName(lastName), middleName(middleName), email(email),
      registrationDate(registrationDate), drivingExperience(drivingExperience), role(role) {
    this->id = -1;
}

User::User(const QString &email) : email(email) {

}

User::User() {

}
