#include "Person.h"
#include <iostream>

#include <string>
using namespace std;

Person::Person(string login, string password) : login(login), password(password) {}

string Person::getLogin() {
    return login;
}
string Person::getPassword() {
    return password;
}
void Person::setLogin(string login) {
    this->login = login;
}
void Person::setPassword(string password) {
    this->password = password;
}