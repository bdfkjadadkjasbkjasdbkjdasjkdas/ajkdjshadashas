#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <sstream>
#include "People.h"
#include "Student.h"
#include "Person.h"

using namespace std;

string hashPassword(const string& password) {
    std::hash<std::string> hasher;
    size_t hash = hasher(password);
    std::stringstream ss;
    ss << std::hex << hash;
    return ss.str();
}

void saveLogin(const string& filename, vector<Person>& persons) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (auto& person : persons) {
            outfile << person.getLogin() << " " << hashPassword(person.getPassword()) << endl;
        }
        outfile.close();
        cout << "Логин и пароль сохранены в файл login.txt" << endl;
    }
}

void loadLogin(const string& filename, vector<Person>& persons) {
    ifstream infile(filename);
    if (infile.is_open()) {
        string login, password;
        while (infile >> login >> password) {
            persons.push_back(Person(login, password));
        }
        infile.close();
    }
}


void registration(vector<Person>& persons) {
    string login, password;
    cout << "Введите логин для создания: ";
    cin.ignore();
    getline(cin, login);
    cout << "Введите пароль для создания: ";
    cin.ignore();
    getline(cin, password);
    persons.push_back(Person(login, password));
}

bool login(vector<Person>& persons) {
    string login, password;
    cout << "Введите логин: ";
    cin.ignore();
    getline(cin, login);
    cout << "Введите пароль: ";
    cin.ignore();
    getline(cin, password);
    for (auto& person : persons) {
        if (person.getLogin() == login && hashPassword(person.getPassword()) == hashPassword(password)) {
            cout << "Вы успешно вошли в систему как работник банка!" << endl;
            return true;
        }
    }
    cout << "Неверный логин или пароль." << endl;
    return false;
}

void loadPeopleData(const string& filename, vector<People>& people) {
    ifstream infile(filename);
    if (infile.is_open()) {
        string name;
        int score, credit;
        while (infile >> name >> score >> credit) {
            people.push_back(People(name, score, credit));
        }
        infile.close();
    }
}

void savePeopleData(const string& filename, vector<People>& people) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (auto& person : people) {
            outfile << person.getNames() << " " << hashPassword(to_string(person.getScores())) << " " << person.getCredits() << endl;
        }
        outfile.close();
    }
}

// void loadScoresData(const string& filename, vector<int>& scores) {
//     ifstream infile(filename);
//     if (infile.is_open()) {
//         string name;
//         int score;
//         while (infile >> name >> score) {
//             scores.push_back(score);
//         }
//         infile.close();
//     }
// }

// void saveScoresData(const string& filename, const vector<int>& scores) {
//     ofstream outfile(filename);
//     if (outfile.is_open()) {
//         for (const auto& score : scores) {
//             outfile << score << endl;
//         }
//         outfile.close();
//     }
// }


void addPerson(vector<People>& people) {
    string names;
    int scores = 0;
    cout << "Введите имя человека: ";
    cin.ignore();
    getline(cin, names);
    people.push_back(People(names, scores, 0));
}


void addScore(vector<People>& people) {
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
}


void addCredit(vector<People>& people) {
    string names;
    int credits;
    cout << "Введите имя человека: ";
    cin.ignore();
    getline(cin, names);
    cout << "Введите кредит: ";
    cin >> credits;
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
}


void payCredit(vector<People>& people) {
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
}


void showPeopleInfo(vector<People>& people) {
    cout << "Информация обо всех людях:" << endl;
    for (int i = 0; i < people.size(); i++) {
        people[i].information();
    }
}

void showInfo() {
    cout << "Выберите действие:" << endl;
    cout << "1. Регистрация" << endl;
    cout << "2. Войти" << endl;
    cout << "3. Выйти" << endl;
}

void showInfo2() {
    cout << "Выберите действие:" << endl;
    cout << "1. Добавить человека" << endl;
    cout << "2. Добавить счет" << endl;
    cout << "3. Добавить кредит" << endl;
    cout << "4. Оплатить кредит" << endl;
    cout << "5. Посмотреть информацию обо всех людях" << endl;
    cout << "6. Выйти" << endl;
}
int main() {
    setlocale(LC_ALL, "RUS");
    vector<People> people;
    vector<int> scores;
    vector<Person> persons;

    loadLogin("login.txt", persons);
    loadPeopleData("people_data.txt", people);
    // loadScoresData("scores_data.txt", scores);


    char choice;
    Student student1("Ivan", 0, 10000);
    student1.information();
    bool isBreak = true;
    bool isLogin = true;

    char choice2;
    while (isLogin) {
        showInfo();
        cin >> choice2;
        switch (choice2) {
        case '1':
            registration(persons);
            break;
        case '2':
            if (login(persons)) {
                isLogin = false;
            };
            break;
        case '3':
            isLogin = false;
            isBreak = false;
            break;
        }
    }

    while (isBreak) {
        showInfo2();
        cin >> choice;
        switch (choice) {
        case '1':
            addPerson(people);
            break;
        case '2':
            addScore(people);
            break;
        case '3':
            addCredit(people);
            break;
        case '4':
            payCredit(people);
            break;
        case '5':
            showPeopleInfo(people);
            break;
        case '6':
            cout << "Выход из программы." << endl;
            isBreak = false;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    }

    saveLogin("login.txt", persons);
    savePeopleData("people_data.txt", people);
    // saveScoresData("scores_data.txt", scores);
    return 0;
}