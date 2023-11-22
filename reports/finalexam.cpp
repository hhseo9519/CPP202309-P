#include<iostream>
#include<vector>
#include<string>
#include"program.h"
using namespace std;

int main() {
	//프로그램 참여 신청받기
	cout << "매칭 프로그램에 참여하시겠습니까?(Y/N) : ";
	char OX;
	cin >> OX;
	if (OX != 'y' && OX != 'Y') {
		cout << "프로그램을 종료하겠습니다!!";
		return 0;
	}
	else {
		cout << "환영합니다!" << endl << endl;
	}
	vector<Student>Profiles;
	int count = 0;
	while (true)
	{

		Student student;
		cout << "참여자의 정보를 입력하시오 " << endl;
		cout << "이름 : ";
		cin >> student.name;
		cout << "참여자의 인스타 아이디를 입력하시오 : ";
		cin >> student.insta_ID;
		cout << "참여자의 성별을 입력하시오 (남자일 경우 0, 여자일 경우 1)";
		cin >> student.gender;
		while (student.gender != 0 && student.gender != 1) {
			cout << "다시 입력해주세요 (남자일 경우 0, 여자일 경우 1)";
			cin >> student.gender;
		}
		cout << endl;
		count++;

		if (count == 10) {
			cout << "매칭을 위한 최소한의 인원이 모두 채워졌습니다 계속 인원을 추가하시겠습니까?(O/X) :";
			cin >> OX;

			if (OX != 'o' && OX != 'O') {
				cout << "연애 검사를 시작하겠습니다" << endl;
				break;
			}
			else {
				cout << "계속 추가하신 후 종료를 원하시면 이름에 quit을 기입해주세요" << endl;
			}
		}
		if (student.name == "quit") {
			break;
		}
		Profiles.push_back(student);
	}
	
}
