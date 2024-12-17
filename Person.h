#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string login;
    string password;
public: 
    Person(string login, string password);

    void setLogin(string login);
    void setPassword(string password);
    string getLogin();
    string getPassword();
};
А
#endif // !PERSON_H