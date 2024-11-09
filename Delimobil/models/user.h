#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

class User {
private:
    long id;
    QString fullName;
    QString email;
    QDateTime registrationDate;
    short drivingExperience;

public:
    User(long id, const QString& fullName, const QString& email,
         const QDateTime& registrationDate, short drivingExperience);

    long getId() const {
        return id;
    }

    void setId(long id) {
        this->id = id;
    }

    QString getFullName() const {
        return fullName;
    }

    void setFullName(const QString& fullName) {
        this->fullName = fullName;
    }

    QString getEmail() const {
        return email;
    }

    void setEmail(const QString& email) {
        this->email = email;
    }

    QDateTime getRegistrationDate() const {
        return registrationDate;
    }

    void setRegistrationDate(const QDateTime& registrationDate) {
        this->registrationDate = registrationDate;
    }

    short getDrivingExperience() const {
        return drivingExperience;
    }

    void setDrivingExperience(short drivingExperience) {
        this->drivingExperience = drivingExperience;
    }
};

#endif // USER_H
