#include "Student.h"
#include "People.h"
#include <iostream>

#include <string>
using namespace std;

Student::Student(string names, int scores, int credits) : People(names, scores, credits) {}
void Student::information() {
    cout << "Пример информации о студенте:" << endl;
    cout << "Имя: " << getNames() << endl;
    cout << "Счет: " << getScores() << endl;
    cout << "Кредит: " << getCredits() << endl;
}
void Student::information(string names, int scores, int credits) {
    cout << "Информация о студенте: " << endl;
    cout << "Имя: " << names << endl;
    cout << "Счет: " << scores << endl;
    cout << "Кредит: " << credits << endl;
}
