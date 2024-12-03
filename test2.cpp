#include <iostream>
#include <string>
#include <vector>
#include "People.h"
#include "Student.h"

using namespace std;

int main() {
    
    setlocale(LC_ALL, "RUS");
    vector<People> people;
    vector<int> scores;
    int choice;
    Student student1("Ivan", 0, 10000);
    student1.information();

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить человека" << endl;
        cout << "2. Добавить счет" << endl;
        cout << "3. Добавить кредит" << endl;
        cout << "4. Оплатить кредит" << endl;
        cout << "5. Посмотреть информацию обо всех людях" << endl;
        cout << "6. Выйти" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            string names;
            int scores = 0;
            cout << "Введите имя человека: ";
            cin.ignore();
            getline(cin, names);
            people.push_back(People(names, scores, 0));

            break;
        }
        case 2: {
            string names;
            int scores;
            cout << "Введите имя человека: ";
            cin.ignore();
            getline(cin, names);
            cout << "Введите ваш счет: ";
            cin >> scores;

            bool found = false;
            for (int i = 0; i < people.size(); i++) {
                if (people[i].getNames() == names) {
                    people[i].addScore(scores);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Человек с таким именем не найден." << endl;
            }
            break;
        }
        case 3: {
            string names;
            int credits;
            cout << "Введите имя человека: ";
            cin.ignore();
            getline(cin, names);
            cout << "Введите кредит: ";
            cin >> credits;
            cout << "Вы взяли кредит суммой: " << credits << " на человека " << names << endl;
            bool found = false;
            for (int i = 0; i < people.size(); i++) {
                if (people[i].getNames() == names) {
                    people[i].addCredit(credits);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Человек с таким именем не найден." << endl;
            }
            break;
        }
        case 4: {
            string names;
            int creditsPay;
            cout << "Введите имя человека: ";
            cin.ignore();
            getline(cin, names);
            cout << "Введите сумму оплаты кредита: ";
            cin >> creditsPay;
            bool found = false;
            for (int i = 0; i < people.size(); i++) {
                if (people[i].getNames() == names) {
                    people[i].payCredit(creditsPay);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Человек с таким именем не найден." << endl;
            }
            break;
        }
        case 5: {
            cout << "Информация обо всех людях:" << endl;
            for (int i = 0; i < people.size(); i++) {
                people[i].information();
            }
            break;
        }
        case 6: {
            cout << "Выход из программы." << endl;
            return 0;
        }
        default: {
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
        }
    }
    return 0;
}