#include "authorizeduser.h"

AuthorizedUser::AuthorizedUser() {
    this->car = nullptr;
}

AuthorizedUser& AuthorizedUser::instance() {
    static AuthorizedUser instance;
    return instance;
}

void AuthorizedUser::setUser(User& user) {
    this->user = user;
}

User& AuthorizedUser::getUser() {
    return this->user;
}

void AuthorizedUser::setCar(Car* car) {
    this->car = car;
}

Car* AuthorizedUser::getCar() {
    return this->car;
}
