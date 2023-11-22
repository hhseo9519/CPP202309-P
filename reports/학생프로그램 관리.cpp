#include "program.h"

Student::Student(string name, string insta_ID) {
    this->name = name;
    this->insta_ID = insta_ID;
}
Student::Student() {
    name = "";
    insta_ID = "";
}
void Student::Print_Profile() {
    cout << name << " " << insta_ID << endl;
}
void Student::Focal(int ans) {
    switch (ans) {
    case 1:
        focal -= 5;
        break;
    case 2:
        focal -= 3;
        break;
    case 3:
        break;
    case 4:
        focal += 3;
        break;
    case 5:
        focal += 5;
        break;
    }
}

void Student::Conflict(int ans) {
    switch (ans) {
    case 1:
        conflict -= 5;
        break;
    case 2:
        conflict -= 3;
        break;
    case 3:
        break;
    case 4:
        conflict += 3;
        break;
    case 5:
        conflict += 5;
        break;
    }
}

void Student::Mind(int ans) {
    switch (ans) {
    case 1:
        mind -= 5;
        break;
    case 2:
        mind -= 3;
        break;
    case 3:
        break;
    case 4:
        mind += 3;
        break;
    case 5:
        mind += 5;
        break;
    }
}

void Student::Date(int ans) {
    switch (ans) {
    case 1:
        date -= 5;
        break;
    case 2:
        date -= 3;
        break;
    case 3:
        break;
    case 4:
        date += 3;
        break;
    case 5:
        date += 5;
        break;
    }
}

void Student::Proportion(int ans) {
    switch (ans) {
    case 1:
        mind -= 5;
        break;
    case 2:
        mind -= 3;
        break;
    case 3:
        break;
    case 4:
        mind += 3;
        break;
    case 5:
        mind += 5;
        break;
    }
}