#ifndef AUTHORIZEDUSER_H
#define AUTHORIZEDUSER_H

#include "user.h"
#include "car.h"
#include "rentmode.h"
#include <QObject>
#include <QTimer>
#include <QDebug>

class AuthorizedUser : public QObject
{
    Q_OBJECT
private:
    User* user;
    Car* car;
    RentMode rentMode;
    QTimer timer;
    double priceIncrement;
    double tripPrice;

    explicit AuthorizedUser(QObject* parent = nullptr);

private slots:
    void updateTripPrice();

signals:
    void tripPriceUpdated(double newPrice);

public:
    static AuthorizedUser& instance(QObject* parent = nullptr);

    void setUser(User* user);
    User* getUser();
    void setCar(Car* car);
    Car* getCar();
    void setRentMode(RentMode rentMode);
    RentMode getRentMode();
    void setTripPrice(double tripPrice);
    double getTripPrice();
    void setPriceIncrement(double priceIncrement);
    double getPriceIncrement();

    void startMinuteTimer();
    void startHourlyTimer();
    void stopTimer();

    AuthorizedUser(const AuthorizedUser&) = delete;
    AuthorizedUser& operator=(const AuthorizedUser&) = delete;
};

#endif // AUTHORIZEDUSER_H
