#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	string name;
	string insta_ID;
	int index1; // 학생 쌍 중 첫 번째 학생의 인덱스
	int index2; // 학생 쌍 중 두 번째 학생의 인덱스

	double percentage;
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
