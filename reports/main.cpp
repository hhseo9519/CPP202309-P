#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <iterator>
#include<climits>
#include"program.h"
using namespace std;
string Focal[5] = {
	"�����ϴ� ����� ���� ���� �׻���� �� �� �ְ� Ƽ�� ����",
"ȥ�� ������ �ϸ� �ɽ��Ұ� ����",
"���ΰ� ���� �� ���� ������ �� �̾߱� �ϱ� ��ƴ�",
"���ΰ� ������ ����� ���� �� ���� ��ȹ ¥�Ⱑ ����� �ʴ�",
"����Ʈ �� �ϰ� ������ ���϶�� �� �� �� �̾߱� ���� ���Ѵ�" };
string conflict[5] = {
	"���µ� '������ ��' ��� ������ ���� �����ϴ�",
"ȭ�� ���� �ٷ� Ǫ�°� ���ٴ� �ð��� �ʿ��ϴ�",
"���ο��� ������ ���� �ִ��� ȥ�ڼ� �ذ��ϴ� ���̴�",
"������ ������� ��ġ�� �ذ��ϱ⺸�ٴ� ���ϰ� �ʹ� ",
"���� ���ο��� �����޴� ���� ���� �Ⱦ��Ѵ�" };
string mind[5] = { "���ο��� ��� ����� Ȯ�ιް� �ʹ�",
"���� �ڽ� ������ ���� ����� �Ŵ� ������� �ʿ��ϴٰ� �����Ѵ�",
"���� ���ְ� �׻� �ϰ�ʹ�",
"���ָ� �� ������ ���ο��� ǫ ������ ������ �ִ�",
"������ �����ð� ������ �ȵǸ� �Ҿ��ؼ� �ٸ� ���� �ϱ� ��ƴ�" };
string date[5] = { "������ ���� �꺸�� �ٴٰ� ����",
"��ϴ� ���� �����Ѵ�",
"������ �� ���� �Դ°͵� �� ����",
"���� ���� �ִ°� �� �ߵ�� ���̴�",
"���� ���ø� ���� ������ ���̴�",
};
string balance[5] = { "���� ������ ���ؼ� �Ϸ����� ���� �־��ְ� �ʹ�",
"������ ������ �� �߿��ϰ� �����Ѵ�",
"���ָ� �ϸ� ģ������� ������ ���� �پ��� ���̴�",
"������ ���� ������ �ϴ��� �׻� �ñ��ϴ�",
"���� ������ ������ �̻� �� �ϱ� ��ƴ�" };

int Student::count = 0;



int main() {

	char OX;
	do {
		cout << "��Ī ���α׷��� �����Ͻðڽ��ϱ�? (Y/N): ";
		cin >> OX;

		if (OX != 'y' && OX != 'Y' && OX != 'n' && OX != 'N') {
			cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
		}

	} while (OX != 'y' && OX != 'Y' && OX != 'n' && OX != 'N');

	if (OX == 'n' || OX == 'N') {
		cout << "���α׷��� �����ϰڽ��ϴ�!!" << endl;
		return 0;
	}
	else {
		cout << "ȯ���մϴ�!" << endl << endl;

	}
	//�л����� �����ϴ� ���� ����
	vector<Student>Profiles;
	//�ο��� üũ�� ���� ���� ����
	int county = 0;

	while (true) {
		Student student;
		cout << "�������� ������ �Է��Ͻÿ� " << endl;
		cout << "�̸� : ";
		cin >> student.name;
		cout << "�������� �ν�Ÿ ���̵� �Է��Ͻÿ� : ";
		cin >> student.insta_ID;



		while (true) {
			try {
				cout << "�������� ������ �Է��Ͻÿ� (������ ��� 0, ������ ��� 1): ";
				cin >> student.gender;

				if (cin.fail()) {
					throw runtime_error("�Է��� �ùٸ��� �ʽ��ϴ�. ���ڸ� �Է��ϼ���.");
				}

				if (student.gender != 0 && student.gender != 1) {
					throw invalid_argument("0 �Ǵ� 1�� �Է��ϼ���");
				}

				break;
			}
			catch (exception& e) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "���� : " << e.what() << endl;
			}
		}


		cout << "�Է¹��� ����: " << student.gender << endl;


		cout << endl;
		county++;

		if (county == 10) {
			do {
				cout << "��Ī�� ���� �ּ����� �ο��� ��� ä�������ϴ�. ��� �ο��� �߰��Ͻðڽ��ϱ�? (O/X): ";
				cin >> OX;

				if (OX != 'o' && OX != 'O' && OX != 'x' && OX != 'X') {
					cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
				}

			} while (OX != 'o' && OX != 'O' && OX != 'x' && OX != 'X');

			if (OX == 'x' || OX == 'X') {
				cout << "���� �˻縦 �����ϰڽ��ϴ�" << endl;
				break;
			}
			else {
				cout << "��� �߰��Ͻ� �� ���Ḧ ���Ͻø� �̸��� quit�� �������ּ���" << endl;
			}
		}

		if (student.name == "quit") {
			break;
		}
		//�л����� �������� vector�� ����ֱ�
		Profiles.push_back(student);
	}
	int FINISH_TEST = 0;
	int num = 0;
	cout << "�׽�Ʈ�� �����ϰڽ��ϴ� ������ �Է��� ������� �˻翡 �����ּ���!" << endl;
	for (int k = 0; k < size(Profiles); k++) {
		int a;
		int answerCount[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� " << "(�ſ� �ƴϴ�=1, �ƴϴ�=2, ����=3, �׷���=4, �ſ� �׷���=5)" << endl;

			cout << Focal[i] << endl;

			int answer;
			while (true) {

				cout << "�ټ� ���� �� �ϳ��� �������ּ���" << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): " << endl;
				}
				else {
					break;
				}
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (i == 4) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}



		int answerCount2[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� " << "(�ſ� �ƴϴ�=1, �ƴϴ�=2, ����=3, �׷���=4, �ſ� �׷���=5)" << endl;

			cout << conflict[i] << endl;

			int answer;
			while (true) {

				cout << "�ټ� ���� �� �ϳ��� �������ּ���: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): " << endl;
				}
				else {
					break;
				}
			}

			// �� �亯�� ���� ���� ����
			answerCount2[answer - 1]++;
			if (i == 4) {
				Profiles[k].conflict = answerCount2[0] * (-5) + answerCount2[1] * (-3) + answerCount2[3] * 3 + answerCount2[4] * 5;

			}
		}
		int answerCount3[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� " << "(�ſ� �ƴϴ�=1, �ƴϴ�=2, ����=3, �׷���=4, �ſ� �׷���=5)" << endl;

			cout << mind[i] << endl;

			int answer;
			while (true) {

				cout << "�ټ� ���� �� �ϳ��� �������ּ���: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): " << endl;
				}
				else {
					break;
				}
			}


			// �� �亯�� ���� ���� ����
			answerCount3[answer - 1]++;
			if (i == 4) {
				Profiles[k].mind = answerCount3[0] * (-5) + answerCount3[1] * (-3) + answerCount3[3] * 3 + answerCount3[4] * 5;

			}
		}
		int answerCount4[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� " << "(�ſ� �ƴϴ�=1, �ƴϴ�=2, ����=3, �׷���=4, �ſ� �׷���=5)" << endl;

			cout << date[i] << endl;

			int answer;
			while (true) {

				cout << "�ټ� ���� �� �ϳ��� �������ּ���: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): " << endl;
				}
				else {
					break;
				}
			}


			// �� �亯�� ���� ���� ����
			answerCount4[answer - 1]++;
			if (i == 4) {
				Profiles[k].date = answerCount4[0] * (-5) + answerCount4[1] * (-3) + answerCount4[3] * 3 + answerCount4[4] * 5;

			}
		}
		int answerCount5[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� " << "(�ſ� �ƴϴ�=1, �ƴϴ�=2, ����=3, �׷���=4, �ſ� �׷���=5)" << endl;

			cout << balance[i] << endl;

			int answer;
			while (true) {

				cout << "�ټ� ���� �� �ϳ��� �������ּ���: " << endl;
				cin >> answer;
				cout << endl;

				if (cin.fail() || answer < 1 || answer > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): " << endl;
				}
				else {
					break;
				}
			}


			// �� �亯�� ���� ���� ����
			answerCount5[answer - 1]++;
			if (i == 4) {
				Profiles[k].proportion = answerCount5[0] * (-5) + answerCount5[1] * (-3) + answerCount5[3] * 3 + answerCount5[4] * 5;


			}
		}



	}//�̰� �˻��ϴ� ��ü for���� ��ȣ
	//���ϴ� ���� ���� �ű�� ��Ī���� Ȯ��
	cout << "�� �л� ���� : " << Profiles[0].count << endl;

	cout << "��Ī ��� �м����Դϴ�" << endl;

	int Mvalue = numeric_limits<int>::max(); // �ʱⰪ�� ������ �ִ밪���� ����


	// ���� ���� focal ���� ���� �� �л��� ������ ����
	Student minFocalStudent1, minFocalStudent2;
	vector<Student> Results;
	int minIndex1 = -1, minIndex2 = -1;
	int minValue = INT_MAX;
	// ��� �л��鿡 ���� ���� ����
	for (int i = 0; i < size(Profiles); ++i) {
		for (int j = i + 1; j < size(Profiles); ++j) {
			// i�� j �л��� ���� ���� ����
			Student result = Profiles[i] - Profiles[j];

			result.index1 = i;
			result.index2 = j;

			// �������� �ο�
			if (abs(result.focal) <= 20) {
				result.value -= 5;
			}

			// percentage ��� ����
			result.percentage = (50 - result.value) * 2.0;

			Results.push_back(result);
		}
	}

	// ��� ���
	for (int i = 0; i < Results.size(); ++i) {
		if (Results[i].value < minValue) {
			minValue = Results[i].value;
			minIndex1 = Results[i].index1;
			minIndex2 = Results[i].index2;
		}
	}
	cout << "���� Ŀ���� �� �� �ִ� �л� 1: ";
	Profiles[minIndex1].Print_Profile();
	cout << "���� Ŀ���� �� �� �ִ� �л� 2: ";
	Profiles[minIndex2].Print_Profile();


	cout << "�ٸ� ����Ŀ���� �� �� �ִ� ���ɼ��� ���� �л����� �˷��帮�ڽ��ϴ�!!" << endl;
	cout << "���� Ŀ���� �� Ȯ���� 70% �̻��� �л����� ����:" << endl;

	//70�� �̻��� �л��� ���
	for (int i = 0; i < ((Profiles[0].count) * (Profiles[0].count - 1) / 2); i++) {
		if (Results[i].percentage > 70) {
			cout << Results[i].index1 << "��" << Results[i].index2 << endl;
		}
	}


	cout << "���� �ο� ������ �˷��帮�ڽ��ϴ�" << endl;

	ifstream is{ "Rate_Score.txt" };
	if (!is) {
		cerr << "���� �ο� ������ ����Դϴ�!!" << endl;
		exit(1);
	}

	string line;
	while (getline(is, line)) {
		cout << line << endl;
	}




	return 0;
}

