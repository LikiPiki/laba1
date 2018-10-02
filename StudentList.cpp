#include <iostream>

#include "StudentList.h"

using namespace std;

Student **StudentList::getData() const {
    return data;
}

int StudentList::getSize() const {
    return size;
}

StudentList::StudentList() {
    this->size = 0;
}

StudentList &StudentList::add(Student &st) {
    this->size++;
    auto **copy = new Student*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->data[i];
    }
    this->data = new Student*[this->size];
    for (int i = 0; i < this->size - 1; ++i) {
        this->data[i] = copy[i];
    }
    this->data[this->size - 1] = &st;
    delete []copy;
    return *this;
}

void StudentList::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << *this->data[i] << endl;
    }
}

StudentList &StudentList::remove(int index) {
    if (index >= this->size || index < 0) {
        cout << "Cant delete, try onother index" << endl;
    } else {
        auto **copy = new Student*[this->size];
        for (int i = 0; i < this->size; ++i) {
            copy[i] = this->data[i];
        }
        this->size--;
        this->data = new Student*[this->size];
        int k = 0;
        for (int i = 0; i < this->size + 1; ++i) {
            if (i == index) {
                continue;
            }
            this->data[k] = copy[i];
            k++;
        }

        delete []copy;
    }
    return *this;
}



