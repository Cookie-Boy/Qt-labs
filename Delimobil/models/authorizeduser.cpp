#include "authorizeduser.h"

AuthorizedUser::AuthorizedUser(QObject* parent)
    : QObject(parent), user(nullptr), car(nullptr), rentMode(RentMode::None), priceIncrement(0), tripPrice(0)
{
    connect(&timer, &QTimer::timeout, this, &AuthorizedUser::updateTripPrice);
}

AuthorizedUser& AuthorizedUser::instance(QObject* parent) {
    static AuthorizedUser instance(parent);
    return instance;
}

void AuthorizedUser::updateTripPrice() {
    qDebug() << "Update trip price...";
    tripPrice += priceIncrement;
    emit tripPriceUpdated(tripPrice);
}

void AuthorizedUser::setUser(User* user) {
    this->user = user;
}

User* AuthorizedUser::getUser() {
    return this->user;
}

void AuthorizedUser::setCar(Car* car) {
    this->car = car;
}

Car* AuthorizedUser::getCar() {
    return this->car;
}

void AuthorizedUser::setRentMode(RentMode rentMode) {
    this->rentMode = rentMode;
}

RentMode AuthorizedUser::getRentMode() {
    return this->rentMode;
}

void AuthorizedUser::setTripPrice(double tripPrice) {
    this->tripPrice = tripPrice;
}

double AuthorizedUser::getTripPrice() {
    return this->tripPrice;
}

void AuthorizedUser::setPriceIncrement(double priceIncrement) {
    this->priceIncrement = priceIncrement;
}

double AuthorizedUser::getPriceIncrement() {
    return this->priceIncrement;
}

void AuthorizedUser::startMinuteTimer() {
    timer.setInterval(60 * 1000);
    timer.start();
}

void AuthorizedUser::startHourlyTimer() {
    timer.setInterval(60 * 60 * 1000);
    timer.start();
}

void AuthorizedUser::stopTimer() {
    timer.stop();
}
