#include "User.h"

User::User(long id, const QString& fullName, const QString& email,
           const QDateTime& registrationDate, short drivingExperience)
    : id(id), fullName(fullName), email(email),
      registrationDate(registrationDate), drivingExperience(drivingExperience) {
}
