#include<iostream>
#include<vector>
#include<string>
#include <iterator>
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
	string strArray[6] = { "q1", "q2", "q3", "q4", "q5", "q6" };
	while (true)
	{

		Student student;
		cout << "참여자의 정보를 입력하시오 " << endl;
		cout << "이름 : ";
		cin >> student.name;
		cout << "참여자의 인스타 아이디를 입력하시오 : ";
		cin >> student.insta_ID;
		while (true) {
			cout << "참여자의 성별을 입력하시오 (남자일 경우 0, 여자일 경우 1): ";
			cin >> student.gender;
			if (cin.fail()) {
				cout << "잘못된 입력입니다. 숫자를 입력하세요." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else if (student.gender == 0 || student.gender == 1) {
				break;
			}
			else {
				cout << "잘못된 입력입니다. 0 또는 1을 입력하세요." << endl;
			}
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
	int FINISH_TEST = 0;
	int num = 0;
	for (int k = 0; k < size(Profiles); k++) {

		int answerCount[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 6; ++i) {

			cout << "문제 " << i + 1 << " 번 " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if ( i== 5) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		//테스트를 위한 코드
		cout << endl;
		cout << "테스트 값 :" << Profiles[0].focal << endl;

		int answerCount2[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 6; ++i) {

			cout << "문제 " << i + 1 << " 번 " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount2[answer - 1]++;
			if (i==5) {
				Profiles[k].conflict = answerCount2[0] * (-5) + answerCount2[1] * (-3) + answerCount2[3] * 3 + answerCount2[4] * 5;

			}
		}
		int answerCount3[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 6; ++i) {

			cout << "문제 " << i + 1 << " 번 " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount3[answer - 1]++;
			if (i == 5) {
				Profiles[k].mind = answerCount3[0] * (-5) + answerCount3[1] * (-3) + answerCount3[3] * 3 + answerCount3[4] * 5;

			}
		}
		int answerCount4[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 6; ++i) {

			cout << "문제 " << i + 1 << " 번 " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount4[answer - 1]++;
			if (i== 5) {
				Profiles[k].date = answerCount4[0] * (-5) + answerCount4[1] * (-3) + answerCount4[3] * 3 + answerCount4[4] * 5;

			}
		}
		int answerCount5[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 6; ++i) {

			cout << "문제 " << i + 1 << " 번 " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount5[answer - 1]++;
			if (i == 5) {
				 Profiles[k].proportion = answerCount5[0] * (-5) + answerCount5[1] * (-3) + answerCount5[3] * 3 + answerCount5[4] * 5;


			}
		}


	}//이건 검사하는 전체 for문의 괄호

}// <----이건 int main의 괄호