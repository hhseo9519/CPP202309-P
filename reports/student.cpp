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
    // name�� insta_ID�� ���ڿ��μ� ������ �ǹ̰� �����Ƿ� �����մϴ�.
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
//������ ���� �迭���� �� �������