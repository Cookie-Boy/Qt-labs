#include "car.h"

Car::Car() {}

// Constructor with all fields
Car::Car(long id, const QString &name, short rating, const QString &category,
         const QString &transmission, const QString &driveType,
         double engineCapacity, double power, QString imagePath, bool hasHeatedSeats,
         bool hasHeatedSteeringWheel, bool hasParkingSensors, const QPair<QDate, QDate> &blockedPeriod)
    : id(id), name(name), rating(rating), category(category), transmission(transmission),
      driveType(driveType), engineCapacity(engineCapacity), power(power), imagePath(imagePath), hasHeatedSeats(hasHeatedSeats),
      hasHeatedSteeringWheel(hasHeatedSteeringWheel), hasParkingSensors(hasParkingSensors), blockedPeriod(blockedPeriod) {}

Car::Car(const QString &name, short rating, const QString &category,
    const QString &transmission, const QString &driveType,
    double engineCapacity, double power, QString imagePath, bool hasHeatedSeats,
         bool hasHeatedSteeringWheel, bool hasParkingSensors, const QPair<QDate, QDate> &blockedPeriod)
    : name(name), rating(rating), category(category), transmission(transmission),
      driveType(driveType), engineCapacity(engineCapacity), power(power), imagePath(imagePath), hasHeatedSeats(hasHeatedSeats),
      hasHeatedSteeringWheel(hasHeatedSteeringWheel), hasParkingSensors(hasParkingSensors), blockedPeriod(blockedPeriod) {
    this->id = -1;
}

// Getters and Setters
long Car::getId() const { return id; }
void Car::setId(long id) { this->id = id; }

QString Car::getName() const { return name; }
void Car::setName(const QString &name) { this->name = name; }

short Car::getRating() const { return rating; }
void Car::setRating(short rating) { this->rating = rating; }

QString Car::getCategory() const { return category; }
void Car::setCategory(const QString &category) { this->category = category; }

QString Car::getTransmission() const { return transmission; }
void Car::setTransmission(const QString &transmission) { this->transmission = transmission; }

QString Car::getDriveType() const { return driveType; }
void Car::setDriveType(const QString &driveType) { this->driveType = driveType; }

double Car::getEngineCapacity() const { return engineCapacity; }
void Car::setEngineCapacity(double engineCapacity) { this->engineCapacity = engineCapacity; }

double Car::getPower() const { return power; }
void Car::setPower(double power) { this->power = power; }

QString Car::getImagePath() const { return imagePath; }
void Car::setImagePath(QString &imagePath) { this->imagePath = imagePath; }

bool Car::getHasHeatedSeats() const { return hasHeatedSeats; }
void Car::setHasHeatedSeats(bool hasHeatedSeats) { this->hasHeatedSeats = hasHeatedSeats; }

bool Car::getHasHeatedSteeringWheel() const { return hasHeatedSteeringWheel; }
void Car::setHasHeatedSteeringWheel(bool hasHeatedSteeringWheel) { this->hasHeatedSteeringWheel = hasHeatedSteeringWheel; }

bool Car::getHasParkingSensors() const { return hasParkingSensors; }
void Car::setHasParkingSensors(bool hasParkingSensors) { this->hasParkingSensors = hasParkingSensors; }

QPair<QDate, QDate> Car::getBlockedPeriod() const {
    return blockedPeriod;
}

void Car::setBlockedPeriod(const QPair<QDate, QDate> &period) {
    blockedPeriod = period;
}

bool Car::isBlocked() const {
    QDate today = QDate::currentDate();
    return (today >= blockedPeriod.first && today <= blockedPeriod.second);
}
