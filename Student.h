#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "People.h"
using namespace std;

class Student : public People {
public:
    Student(string names, int scores, int credits); 
    void information();
    void information(string names, int scores, int credits);
};


#endif // !STUDENT_H