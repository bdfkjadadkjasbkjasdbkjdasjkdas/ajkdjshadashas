#include "Student.h"
#include "People.h"
#include <iostream>

#include <string>
using namespace std;

Student::Student(string names, int scores, int credits) : People(names, scores, credits) {}
void Student::information() {
    cout << "���: " << getNames() << endl;
    cout << "����: " << getScores() << endl;
    cout << "������: " << getCredits() << endl;
}
void Student::information(string names, int scores, int credits) {
    cout << "���������� � ��������: " << endl;
    cout << "���: " << names << endl;
    cout << "����: " << scores << endl;
    cout << "������: " << credits << endl;
}
