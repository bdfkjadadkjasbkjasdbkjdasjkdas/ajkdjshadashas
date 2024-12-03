#include "People.h"
#include <iostream>

#include <string>
using namespace std;

People::People(string names, int scores, int credits) : names(names), scores(scores), credits(credits), interestAmount(0) {}

string People::getNames() {
    return names;
}
int People::getScores() {
    return scores;
}
int People::getCredits() {
    return credits;
}
double People::getInterestAmount() {
    return interestAmount;
}
void People::setNames(string names) {
    this->names = names;
}
void People::setScores(int scores) {
    this->scores = scores;
}
void People::setCredits(int credits) {
    this->credits = credits;
    interestAmount = credits * 1.1;
}
void People::setCreditX(int creditX) {
    this->interestAmount = creditX;
}
void People::updateCredits(int newCredits) {
    this->credits = newCredits;
    interestAmount = credits * 1.1;
}
void People::addPeople() {
    cout << "Человек " << names << " добавлен в систему." << endl;
}
void People::addScore(int scores) {
    this->scores = scores;
    cout << "Счет " << scores << " добавлен для человека " << names << endl;
}
void People::addCredit(int credits) {
    this->credits = credits * 1.1;
    cout << "Кредит суммой: " << credits * 1.1 << " добавлен для человека " << names << endl;
}
void People::CreditXs(int credits, int creditX) {
    this->credits = credits;
    creditX = credits * 1.1;
    this->interestAmount = creditX;
}
void People::payCredit(int creditsPay) {
    if (creditsPay <= credits) {
        this->credits -= creditsPay;
        cout << "Кредит суммой: " << creditsPay << " оплачен для человека " << names << endl;
    }
    else {
        cout << "Недостаточно средств для оплаты кредита." << endl;
    }
}
void People::information() {
    cout << "Имя: " << getNames() << endl;
    cout << "Счет: " << getScores() << endl;
    cout << "Кредит: " << getCredits() << endl;
}