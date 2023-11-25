#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	string name;
	string insta_ID;
	int gender;
	int focal = 30;
	int conflict = 30;
	int mind = 30;
	int date = 30;
	int proportion = 30;
	Student(string name, string insta_ID);
	Student();
	void Print_Profile();

};

