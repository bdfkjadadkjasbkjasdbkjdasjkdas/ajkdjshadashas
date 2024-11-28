#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People {
private:
    string names;
    int scores;
    int credits;
    double interestAmount; 

public:
    People(string names, int scores, int credits) : names(names), scores(scores), credits(credits), interestAmount(0) {} 
    string getNames() {
        return names;
    }
    int getScores() {
        return scores;
    }
    int getCredits() {
        return credits;
    }
    double getInterestAmount() {
        return interestAmount;
    }
    void setNames(string names) {
        this->names = names;
    }
    void setScores(int scores) {
        this->scores = scores;
    }
    void setCredits(int credits) {
        this->credits = credits;
        interestAmount = credits * 1.1;
    }
    void setCreditX(int creditX) {
        this->interestAmount = creditX;
    }
    void updateCredits(int newCredits) {
        this->credits = newCredits; 
        interestAmount = credits * 1.1;
    }
    void addPeople() {
        cout << "Человек " << names << " добавлен в систему." << endl;
    }
    void addScore(int scores) {
        this->scores = scores; 
        cout << "Счет " << scores << " добавлен для человека " << names << endl;
    }
    void addCredit(int credits) {
        this->credits = credits * 1.1;
        cout << "Кредит суммой: " << credits * 1.1 << " добавлен для человека "<< names << endl; 
    }
    void CreditXs(int credits, int creditX) {
        this->credits = credits;
        creditX = credits * 1.1;
        this->interestAmount = creditX;
    }
    void payCredit(int creditsPay) {
        if (creditsPay <= credits) {
            this->credits -= creditsPay; 
            cout << "Кредит суммой: " << creditsPay << " оплачен для человека " << names << endl;
        } else {
            cout << "Недостаточно средств для оплаты кредита." << endl;
        }
    }
    void information() {
        cout << "Имя: " << getNames() << endl;
        cout << "Счет: " << getScores() << endl;
        cout << "Кредит: " << getCredits() << endl;
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
