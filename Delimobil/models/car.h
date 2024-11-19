#ifndef CAR_H
#define CAR_H

#include <QString>

class Car
{
private:
    long id;
    QString name;
    short rating;
    QString category;
    QString transmission;
    QString driveType;
    double engineCapacity;
    double power;
    QString imagePath;
    bool hasHeatedSeats;
    bool hasHeatedSteeringWheel;
    bool hasParkingSensors;
    bool isBlocked;

public:
    Car();
    Car(long id, const QString &name, short rating, const QString &category,
        const QString &transmission, const QString &driveType,
        double engineCapacity, double power, QString imagePath, bool hasHeatedSeats,
        bool hasHeatedSteeringWheel, bool hasParkingSensors, bool isBlocked);
    Car(const QString &name, short rating, const QString &category,
        const QString &transmission, const QString &driveType,
        double engineCapacity, double power, QString imagePath, bool hasHeatedSeats,
        bool hasHeatedSteeringWheel, bool hasParkingSensors, bool isBlocked);

    // Getters and Setters
    long getId() const;
    void setId(long id);

    QString getName() const;
    void setName(const QString &name);

    short getRating() const;
    void setRating(short rating);

    QString getCategory() const;
    void setCategory(const QString &category);

    QString getTransmission() const;
    void setTransmission(const QString &transmission);

    QString getDriveType() const;
    void setDriveType(const QString &driveType);

    double getEngineCapacity() const;
    void setEngineCapacity(double engineCapacity);

    double getPower() const;
    void setPower(double power);

    QString getImagePath() const;
    void setImagePath(QString &imagePath);

    bool getHasHeatedSeats() const;
    void setHasHeatedSeats(bool hasHeatedSeats);

    bool getHasHeatedSteeringWheel() const;
    void setHasHeatedSteeringWheel(bool hasHeatedSteeringWheel);

    bool getHasParkingSensors() const;
    void setHasParkingSensors(bool hasParkingSensors);

    bool getIsBlocked() const;
    void setIsBlocked(bool isBlocked);
};

#endif // CAR_H
