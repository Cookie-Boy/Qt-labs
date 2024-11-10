#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

class User {
private:
    long id;
    QString firstName;
    QString lastName;
    QString middleName;
    QString email;
    QDateTime registrationDate;
    short drivingExperience;

public:
    User(long id, const QString& firstName, const QString& lastName, const QString& middleName,
               const QString& email, const QDateTime& registrationDate, short drivingExperience);

    User(const QString &email);

    User();

    // ID
   void setId(long id) {
       this->id = id;
   }
   long getId() const {
       return id;
   }

   // First Name
   void setFirstName(const QString& firstName) {
       this->firstName = firstName;
   }
   QString getFirstName() const {
       return firstName;
   }

   // Last Name
   void setLastName(const QString& lastName) {
       this->lastName = lastName;
   }
   QString getLastName() const {
       return lastName;
   }

   // Middle Name
   void setMiddleName(const QString& middleName) {
       this->middleName = middleName;
   }
   QString getMiddleName() const {
       return middleName;
   }

   // Email
   void setEmail(const QString& email) {
       this->email = email;
   }
   QString getEmail() const {
       return email;
   }

   // Registration Date
   void setRegistrationDate(const QDateTime& registrationDate) {
       this->registrationDate = registrationDate;
   }
   QDateTime getRegistrationDate() const {
       return registrationDate;
   }

   // Driving Experience
   void setDrivingExperience(short drivingExperience) {
       this->drivingExperience = drivingExperience;
   }
   short getDrivingExperience() const {
       return drivingExperience;
   }
};

#endif // USER_H
