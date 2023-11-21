#include<iostream>
#include<string>
using namespace std;

class Student {
public: 
	string name;
	string insta_ID;
	int focal;
	int conflict;
	int mind;
	int date;
	int proportion;
	Student(string name, string insta_ID);
	void Focal(int ans);
	void Conflict(int ans);
	void Mind(int ans);
	void Date(int ans);
	void Proportion(int ans);
};