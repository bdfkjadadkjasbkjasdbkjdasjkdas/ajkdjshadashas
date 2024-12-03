#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

class People {
private:
    string names;
    int scores;
    int credits;
    double interestAmount;
public: 
    People(string names, int scores, int credits);

    void setNames(string names);
    void setScores(int scores);
    void setCredits(int credits);
    void setCreditX(int creditX);
    void updateCredits(int newCredits);
    void addPeople();
    void addScore(int scores);
    void addCredit(int credits);
    void CreditXs(int credits, int creditX);
    void payCredit(int creditsPay);
    void information();
    string getNames();
    int getScores();
    int getCredits();
    double getInterestAmount();
};

#endif // !PERSON_H