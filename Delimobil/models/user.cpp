#include "User.h"

User::User(long id, const QString& firstName, const QString& lastName, const QString& middleName,
           const QString& email, const QDateTime& registrationDate, short drivingExperience)
    : id(id), firstName(firstName), lastName(lastName), middleName(middleName), email(email),
      registrationDate(registrationDate), drivingExperience(drivingExperience) {
}

User::User(const QString& firstName, const QString& lastName, const QString& middleName,
           const QString& email, const QDateTime& registrationDate, short drivingExperience)
    : firstName(firstName), lastName(lastName), middleName(middleName), email(email),
      registrationDate(registrationDate), drivingExperience(drivingExperience) {
    this->id = -1;
}

User::User(const QString &email) : email(email) {

}

User::User() {

}
