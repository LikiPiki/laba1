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
    cout << "Student list constructor" << endl;
    this->size = 0;
}

StudentList &StudentList::add(Student &st) {
    this->size++;
    auto **copy = new Student*[this->size];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->data[i];
    }
    copy[this->size - 1] = &st;
    this->data = copy;
    delete []copy;
    return *this;
}

void StudentList::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << *this->data[i];
    }
}

StudentList &StudentList::remove(int index) {
    if (index >= this->size || index < 0) {
        cout << "Cant delete, try another index" << endl;
        return *this;
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



StudentList *StudentList::findGoodStudents() {
    auto *st = new StudentList();
    for (int i = 0; i < this->size; ++i) {
        auto current = this->data[i];
        if (current->isGoodStudent()) {
            st->add(*current);
        }
    }
    return st;
}

StudentList::~StudentList() {
    cout << "StudentList destructor" << endl;
    for (int i = 0; i < this->size; ++i) {
        delete this->data[i];
    }
    this->size = 0;
}

void StudentList::showGoodStudents() {
    auto *st = this->findGoodStudents();
    st->print();
    delete st;
}



