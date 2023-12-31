#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <iterator>
#include<climits>
#include"program.h"
using namespace std;
string Focal[5] = {
	"좋아하는 사람이 생긴 나는 그사람이 알 수 있게 티를 낸다",
"혼자 여행을 하면 심심할거 같다",
"연인과 다툴 때 내가 서운한 걸 이야기 하기 어렵다",
"연인과 여행을 가기로 했을 때 여행 계획 짜기가 어렵지 않다",
"데이트 중 하고 싶은걸 말하라고 할 때 잘 이야기 하지 못한다" };
string conflict[5] = {
	"아픈데 '병원을 가' 라는 연인의 말에 서운하다",
"화가 나면 바로 푸는것 보다는 시간이 필요하다",
"연인에게 서운한 점이 있더라도 혼자서 해결하는 편이다",
"나에게 어려움이 닥치면 해결하기보다는 피하고 싶다 ",
"나는 연인에게 간섭받는 것을 아주 싫어한다" };
string mind[5] = { "연인에게 계속 사랑을 확인받고 싶다",
"나는 자식 교육을 위한 사랑의 매는 어느정도 필요하다고 생각한다",
"나는 연애가 항상 하고싶다",
"연애를 할 때에는 연인에게 푹 빠지는 경향이 있다",
"연인이 일정시가 연락이 안되면 불안해서 다른 일을 하기 어렵다" };
string date[5] = { "여행을 갈때 산보다 바다가 좋다",
"운동하는 것을 좋아한다",
"맛집을 줄 서서 먹는것도 난 좋다",
"집에 오래 있는걸 못 견디는 편이다",
"술을 마시면 흥이 오르는 편이다",
};
string balance[5] = { "아픈 연인을 위해서 하루종일 옆에 있어주고 싶다",
"연인을 나보다 더 중요하게 생각한다",
"연애를 하면 친구들과의 만남이 많이 줄어드는 편이다",
"연인이 지금 무엇을 하는지 항상 궁금하다",
"나의 장점을 세가지 이상 말 하기 어렵다" };

int Student::count = 0;



int main() {

	char OX;
	do {
		cout << "매칭 프로그램에 참여하시겠습니까? (Y/N): ";
		cin >> OX;

		if (OX != 'y' && OX != 'Y' && OX != 'n' && OX != 'N') {
			cout << "유효하지 않은 입력입니다. 다시 입력해주세요." << endl;
		}

	} while (OX != 'y' && OX != 'Y' && OX != 'n' && OX != 'N');

	if (OX == 'n' || OX == 'N') {
		cout << "프로그램을 종료하겠습니다!!" << endl;
		return 0;
	}
	else {
		cout << "환영합니다!" << endl << endl;

	}
	//학생들을 저장하는 벡터 생성
	vector<Student>Profiles;
	//인원수 체크를 위한 변수 생성
	int county = 0;

	while (true) {
		Student student;
		cout << "참여자의 정보를 입력하시오 " << endl;
		cout << "이름 : ";
		cin >> student.name;
		cout << "참여자의 인스타 아이디를 입력하시오 : ";
		cin >> student.insta_ID;



		while (true) {
			try {
				cout << "참여자의 성별을 입력하시오 (남자일 경우 0, 여자일 경우 1): ";
				cin >> student.gender;

				if (cin.fail()) {
					throw runtime_error("입력이 올바르지 않습니다. 숫자를 입력하세요.");
				}

				if (student.gender != 0 && student.gender != 1) {
					throw invalid_argument("0 또는 1을 입력하세요");
				}

				break;
			}
			catch (exception& e) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "에러 : " << e.what() << endl;
			}
		}


		cout << "입력받은 성별: " << student.gender << endl;


		cout << endl;
		county++;

		if (county == 10) {
			do {
				cout << "매칭을 위한 최소한의 인원이 모두 채워졌습니다. 계속 인원을 추가하시겠습니까? (O/X): ";
				cin >> OX;

				if (OX != 'o' && OX != 'O' && OX != 'x' && OX != 'X') {
					cout << "유효하지 않은 입력입니다. 다시 입력해주세요." << endl;
				}

			} while (OX != 'o' && OX != 'O' && OX != 'x' && OX != 'X');

			if (OX == 'x' || OX == 'X') {
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
		//학생들의 개인정보 vector에 집어넣기
		Profiles.push_back(student);
	}
	int FINISH_TEST = 0;
	int num = 0;
	cout << "테스트를 시작하겠습니다 정보를 입력한 순서대로 검사에 응해주세요!" << endl;
	for (int k = 0; k < size(Profiles); k++) {
		int a;
		int answerCount[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 " << "(매우 아니다=1, 아니다=2, 보통=3, 그렇다=4, 매우 그렇다=5)" << endl;

			cout << Focal[i] << endl;

			int answer;
			while (true) {

				cout << "다섯 가지 중 하나를 선택해주세요" << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "다시 입력해주세요 (1~5 사이의 숫자): " << endl;
				}
				else {
					break;
				}
			}

			// 각 답변에 대해 개수 증가
			answerCount[answer - 1]++;
			if (i == 4) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}



		int answerCount2[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 " << "(매우 아니다=1, 아니다=2, 보통=3, 그렇다=4, 매우 그렇다=5)" << endl;

			cout << conflict[i] << endl;

			int answer;
			while (true) {

				cout << "다섯 가지 중 하나를 선택해주세요: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "다시 입력해주세요 (1~5 사이의 숫자): " << endl;
				}
				else {
					break;
				}
			}

			// 각 답변에 대해 개수 증가
			answerCount2[answer - 1]++;
			if (i == 4) {
				Profiles[k].conflict = answerCount2[0] * (-5) + answerCount2[1] * (-3) + answerCount2[3] * 3 + answerCount2[4] * 5;

			}
		}
		int answerCount3[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 " << "(매우 아니다=1, 아니다=2, 보통=3, 그렇다=4, 매우 그렇다=5)" << endl;

			cout << mind[i] << endl;

			int answer;
			while (true) {

				cout << "다섯 가지 중 하나를 선택해주세요: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "다시 입력해주세요 (1~5 사이의 숫자): " << endl;
				}
				else {
					break;
				}
			}


			// 각 답변에 대해 개수 증가
			answerCount3[answer - 1]++;
			if (i == 4) {
				Profiles[k].mind = answerCount3[0] * (-5) + answerCount3[1] * (-3) + answerCount3[3] * 3 + answerCount3[4] * 5;

			}
		}
		int answerCount4[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 " << "(매우 아니다=1, 아니다=2, 보통=3, 그렇다=4, 매우 그렇다=5)" << endl;

			cout << date[i] << endl;

			int answer;
			while (true) {

				cout << "다섯 가지 중 하나를 선택해주세요: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "다시 입력해주세요 (1~5 사이의 숫자): " << endl;
				}
				else {
					break;
				}
			}


			// 각 답변에 대해 개수 증가
			answerCount4[answer - 1]++;
			if (i == 4) {
				Profiles[k].date = answerCount4[0] * (-5) + answerCount4[1] * (-3) + answerCount4[3] * 3 + answerCount4[4] * 5;

			}
		}
		int answerCount5[5] = { 0 };
		// 문제와 답변 받기
		for (int i = 0; i < 5; ++i) {

			cout << "문제 " << i + 1 << " 번 " << "(매우 아니다=1, 아니다=2, 보통=3, 그렇다=4, 매우 그렇다=5)" << endl;

			cout << balance[i] << endl;

			int answer;
			while (true) {

				cout << "다섯 가지 중 하나를 선택해주세요: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "다시 입력해주세요 (1~5 사이의 숫자): " << endl;
				}
				else {
					break;
				}
			}


			// 각 답변에 대해 개수 증가
			answerCount5[answer - 1]++;
			if (i == 4) {
				Profiles[k].proportion = answerCount5[0] * (-5) + answerCount5[1] * (-3) + answerCount5[3] * 3 + answerCount5[4] * 5;


			}
		}



	}//이건 검사하는 전체 for문의 괄호
	//평가하는 문단 점수 매기고 매칭정도 확인
	cout << "총 학생 수는 : " << Profiles[0].count << endl;

	cout << "매칭 결과 분석중입니다" << endl;

	int Mvalue = numeric_limits<int>::max(); // 초기값을 정수의 최대값으로 설정


	// 가장 낮은 focal 값을 가진 두 학생을 저장할 변수
	Student minFocalStudent1, minFocalStudent2;
	vector<Student> Results;
	int minIndex1 = -1, minIndex2 = -1;
	int minValue = INT_MAX;
	// 모든 학생들에 대한 뺄셈 수행
	for (int i = 0; i < size(Profiles); ++i) {
		for (int j = i + 1; j < size(Profiles); ++j) {
			// i와 j 학생에 대한 뺄셈 수행
			Student result = Profiles[i] - Profiles[j];

			result.index1 = i;
			result.index2 = j;

			// 가산점을 부여
			if (abs(result.focal) <= 20) {
				result.value -= 5;
			}

			// percentage 계산 수정
			result.percentage = (50 - result.value) * 2.0;

			Results.push_back(result);
		}
	}

	// 결과 출력
	for (int i = 0; i < Results.size(); ++i) {
		if (Results[i].value < minValue) {
			minValue = Results[i].value;
			minIndex1 = Results[i].index1;
			minIndex2 = Results[i].index2;
		}
	}
	cout << "좋은 커플이 될 수 있는 학생 1: ";
	Profiles[minIndex1].Print_Profile();
	cout << "좋은 커플이 될 수 있는 학생 2: ";
	Profiles[minIndex2].Print_Profile();


	cout << "다른 좋은커플이 될 수 있는 가능성을 가진 학생들을 알려드리겠습니다!!" << endl;
	cout << "좋은 커플이 될 확률이 70% 이상인 학생들의 정보:" << endl;

	//70퍼 이상의 학생들 출력
	for (int i = 0; i < ((Profiles[0].count) * (Profiles[0].count - 1) / 2); i++) {
		if (Results[i].percentage > 70) {
			cout << Results[i].index1 << "과" << Results[i].index2 << endl;
		}
	}


	cout << "점수 부여 기준을 알려드리겠습니다" << endl;

	ifstream is{ "Rate_Score.txt" };
	if (!is) {
		cerr << "점수 부여 기준은 비밀입니다!!" << endl;
		exit(1);
	}

	string line;
	while (getline(is, line)) {
		cout << line << endl;
	}




	return 0;
}

