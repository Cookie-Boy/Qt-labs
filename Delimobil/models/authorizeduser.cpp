#include "authorizeduser.h"

AuthorizedUser::AuthorizedUser() {

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
