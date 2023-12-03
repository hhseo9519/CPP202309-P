#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	string name;
	string insta_ID;
	
	
	int gender = -1;
	int focal = 30;
	int conflict = 30;
	int mind = 30;
	int date = 30;
	int proportion = 30;
	int value = focal + conflict + mind + date + proportion;
	Student(string name, string insta_ID,
		int focal, int conflict, int mind, int date, int proportion);
	Student();
	void Print_Profile();
	Student operator-(const Student& other) const;
		
	
	static int count;
};
