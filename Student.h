//
// Created by Сергей Баталев on 18/09/2018.
//

#include <istream>
#include <ostream>

using namespace std;

#ifndef LABA1_STUDENT_H
#define LABA1_STUDENT_H


class Student {
public:

    Student();
    Student(string fio, int courseNumber);

    virtual ~Student();

    // grades methods
    void setGrades(int *grades);

    double getMiddleGrade() const;
    const int *getGrade() const;

    void showGrades();

    // operator overloading
    friend istream& operator>>(istream& is, Student& st);
    friend ostream& operator<<(ostream& of, Student& st);

    const string &getFio() const;

    void setFio(const string &fio);

    int getCourseNumber() const;

    void setCourseNumber(int courseNumber);

private:
    int courseNumber;
    static const int SIZE = 5;
    string fio;
    double middleGrade;
    int grade[5];
};


#endif //LABA1_STUDENT_H
