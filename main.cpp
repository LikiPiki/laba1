#include <iostream>

#include "Student.h"
#include "StudentList.h"

using namespace std;

int main() {

    auto *st = new Student("test", 2);
    int grades[5] = {3, 4, 5, 2, 4};
    st->setGrades(grades);
    cout << *st << endl;

    auto *st2 = new Student("test", 2);
    int grades2[5] = {5, 4, 5, 4, 5};
    st2->setGrades(grades2);

    auto *l = new StudentList();
    l->add(*st).add(*st2).remove(0);

    l->print();

    delete st;
    delete st2;
    return 0;
}
