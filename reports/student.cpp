#include "program.h"

Student::Student(string name, string insta_ID,
    int focal,int conflict,int mind,int date,int proportion) {
    this->name = name;
    this->insta_ID = insta_ID;
    count++;
   
}
Student::Student() {
    name = "";
    insta_ID = "";
    count++;
}
Student Student::operator-(const Student& other) const {
    // name과 insta_ID는 문자열로서 뺄셈의 의미가 없으므로 무시합니다.
    return Student(name,insta_ID,
        focal - other.focal,
        conflict - other.conflict,
        mind - other.mind,
        date - other.date,
        proportion - other.proportion);
}
void Student::Print_Profile() {
    cout << name << " " << insta_ID << endl;
}
//여기의 문제 배열들을 쭉 집어넣자