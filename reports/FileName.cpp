#include<iostream>
#include<vector>
#include<string>
#include <iterator>
#include"program.h"
using namespace std;
int Check_Score(vector a) {//r그냥 배열로 선언하면 될 거 같은데

}

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
	int FINISH_TEST = 0;
	int num = 0;
	for (int k = 0; k < size(Profiles); k++) {

		vector<int> answerCount(5, 0); // 0으로 초기화된 5개의 원소를 갖는 벡터
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 ";
			cout << " ";//여기에다가 그 문제들을 함수로 놓던지 배열로 놓아서 직접 여기다가 작성하지 않게 만들자;" 배열[i]&&&&
			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].conflict = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0으로 초기화된 5개의 원소를 갖는 벡터
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 ";
			cout << " ";//여기에다가 그 문제들을 함수로 놓던지 배열로 놓아서 직접 여기다가 작성하지 않게 만들자;" 배열[i]&&&&
			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0으로 초기화된 5개의 원소를 갖는 벡터
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 ";
			cout << " ";//여기에다가 그 문제들을 함수로 놓던지 배열로 놓아서 직접 여기다가 작성하지 않게 만들자;" 배열[i]&&&&
			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].mind = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0으로 초기화된 5개의 원소를 갖는 벡터
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 ";
			cout << " ";//여기에다가 그 문제들을 함수로 놓던지 배열로 놓아서 직접 여기다가 작성하지 않게 만들자;" 배열[i]&&&&
			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].date = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0으로 초기화된 5개의 원소를 갖는 벡터
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 ";
			cout << " ";//여기에다가 그 문제들을 함수로 놓던지 배열로 놓아서 직접 여기다가 작성하지 않게 만들자;" 배열[i]&&&&
			int answer;
			cin >> answer;

			// 유효한 답변인지 확인
			while (answer < 1 || answer > 5) {
				cout << "다시 입력해주세요 (1~5 사이의 숫자): ";
				cin >> answer;
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].proportion = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}

	}//이건 검사하는 전체 for문의 괄호

}// <----이건 int main의 괄호
