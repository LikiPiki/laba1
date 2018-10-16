//
// Created by Сергей Баталев on 18/09/2018.
//

#include <iostream>

#include "Student.h"
#include "Utils.h"

using namespace std;

Student::Student(string fio, int courseNumber) {
    cout << "Constructor student" << endl;
    this->fio = fio;
    this->courseNumber = courseNumber;
    this->middleGrade = 0;
    for (int &i : this->grade) {
        i = 0;
    }
}

void Student::setGrades(int *grades) {
    try {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            this->grade[i] = grades[i];
            sum += grade[i];
        }
        this->middleGrade = sum / 5.0;
    } catch (exception e){
        printError("Array out of bounds");
    }
}

istream &operator>>(istream &is, Student &st) {
    is.ignore();
    cout << "Enter a fio" << endl << flush;
    getline(is, st.fio, '\n');
    cout << "Enter a course number" << endl;
    is >> st.courseNumber;
    int grades[st.SIZE];
    int k = 0;
    cout << "Enter grades" << endl;
    for (int &grade : grades) {
        is >> grade;
        grades[++k] = grade;
    }
    st.setGrades(grades);
    auto gradesReal = st.getGrade();
    for (int i = 0; i < 5; ++i) {
        st.middleGrade += gradesReal[i];
    }
    st.middleGrade /= 5.0;
    return is;
}

ostream &operator<<(ostream &of, Student &st) {
    cout << "Name is " << st.fio << " " << "course is "  << st.courseNumber << " " << endl;
    st.showGrades();
    return of;
}

void Student::showGrades() {
    for (int &grade : this->grade) {
        cout << grade << " ";
    }
    cout << endl;
}

Student::Student() {
    cout << "Constructor student" << endl;
}

Student::~Student() {
    cout << "Destructor student" << endl;
    this->fio = "";
    int defaultGrades[5] = {0, 0, 0, 0, 0};
    this->setGrades(defaultGrades);
    this->courseNumber = 0;
    this->middleGrade = 0;
}

const int *Student::getGrade() const {
    return grade;
}

double Student::getMiddleGrade() const {
    return middleGrade;
}
