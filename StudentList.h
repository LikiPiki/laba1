//
// Created by Сергей Баталев on 02/10/2018.
//

#include "Student.h"

#ifndef LABA1_STUDENTLIST_H
#define LABA1_STUDENTLIST_H


class StudentList {
private:
    Student **data;
    int size;

public:
    StudentList &add(Student &st);
    StudentList &remove(int index);
    StudentList();
    Student **getData() const;
    int getSize() const;
    void print();

};


#endif //LABA1_STUDENTLIST_H


