#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People {
private:
    string names;
    int scores;
    int credits;
public:
    People(string names, int scores, int credits) : names(names), scores(scores), credits(credits) {} 
    string getNames() {
        return names;
    }
    int getScores() {
        return scores;
    }
    int getCredits() {
        return credits;
    }
    void addPeople() {
        cout << "Человек " << names << " добавлен в систему." << endl;
    }
    void addScore() {
        scores++; 
        cout << "Счет " << scores << " добавлен для человека " << names << endl;
    }
    void addCredit() {
            cout << "Кредит суммой: " << credits << " добавлен для человека "<< names << endl;
    }
};

class Student : public People {
public:
    Student(string names, int scores, int credits) : People(names, scores, credits) {} 
    void information() {
        cout << "Имя: " << getNames() << endl;
        cout << "Счет: " << getScores() << endl;
        cout << "Кредит: " << getCredits() << endl;
    }
    void information(string names, int scores, int credits) {
        cout << "Информация о студенте: " << endl;
        cout << "Имя: " << names << endl;
        cout << "Счет: " << scores << endl;
        cout << "Кредит: " << credits << endl;
    }
};

int main() {
    vector<People> people;
    int choice;
    Student student1("Ivan", 0, 10000);
    student1.information();

    while (true) { 
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить человека" << endl;
        cout << "2. Добавить кредит" << endl;
        cout << "3. Выйти" << endl;
        cout << "4. Посмотреть информацию обо всех людях" << endl;
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
                int credits;
                cout << "Введите имя человека: ";
                cin.ignore(); 
                getline(cin, names); 
                cout << "Введите кредит: ";
                cin >> credits;
                cout << "Вы взяли кредит суммой: " << credits << " на человека " << names << endl;
                cout << "Вы должны вернуть кредитс 10 процентами, т.е: " << credits * 0.1 + credits << endl;
                bool found = false;
                for (int i = 0; i < people.size(); i++) {
                    if (people[i].getNames() == names) {
                        people[i].addCredit();
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
                cout << "Выход из программы." << endl;
                return 0; 
            }
            case 4: {
                cout << "Инфо: " << endl;
                for (int i = 0; i < people.size(); i++) { 
                    cout << "Человек " << people[i].getNames() << " имеет счет " << people[i].getScores() << " и кредит " << people[i].getCredits() << endl;
                }
                break;
            }
            default: {
                cout << "Неверный выбор. Попробуйте еще раз." << endl;
                break;
            }
        }
    }
    return 0;
}
