#include "program.h"

Student::Student(string name, string insta_ID,
    int focal, int conflict, int mind, int date, int proportion) {
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
    Student result;
    result.name1 = this->name;
    result.name2 = other.name;
    result.focal = this->focal - other.focal;
    result.conflict = this->conflict - other.conflict;
    result.mind = this->mind - other.mind;
    result.date = this->date - other.date;
    result.proportion = this->proportion - other.proportion;
    result.value = abs(result.focal) + abs(result.conflict) + abs(result.mind) + abs(result.date) + abs(result.proportion);
    return result;
}
void Student::Print_Profile() {
    cout << name << " " << insta_ID << endl;
}
