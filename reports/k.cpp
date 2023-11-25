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
//여기의 문제 배열들을 쭉 집어넣자
