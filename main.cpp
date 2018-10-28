#include <iostream>

#include "Student.h"
#include "StudentList.h"

using namespace std;

void menu() {
    const int COUNT = 10;

    auto *list = new StudentList();
    bool fl = true;
    int mode;
    while(fl) {
        cout << "0 - exit" << endl;
        cout << "1 - enter Students from console" << endl;
        cout << "2 - show good students" << endl;
        cout << "3 - delete student" << endl;
        cout << "4 - print list" << endl;
        cin >> mode;
        switch(mode) {
            case 0:
                fl = false;
                break;
            case 1:
                for (int i = 0; i < COUNT; ++i) {
                    auto *st = new Student();
                    cin >> *st;
                    list->add(*st);
                }
                break;
            case 2:
                list->showGoodStudents();
                break;
            case 3:
                int deleting;
                cout << "Enter delete number" << endl;
                cin >> deleting;
                list->remove(deleting);
                break;
            case 4:
                list->print();
                break;
            default:
                fl = false;
                break;
        }
    }

    delete list;
}

int main() {

    menu();

    return 0;
}
