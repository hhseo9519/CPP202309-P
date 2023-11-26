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
