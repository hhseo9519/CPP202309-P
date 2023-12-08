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

	cout << "��Ī ���α׷��� �����Ͻðڽ��ϱ�?(Y/N) : ";
	char OX;
	cin >> OX;
	if (OX != 'y' && OX != 'Y') {
		cout << "���α׷��� �����ϰڽ��ϴ�!!";
		return 0;
	}
	else {
		cout << "ȯ���մϴ�!" << endl << endl;
	}
	vector<Student>Profiles;
	int count = 0;

	while (true)
	{

		Student student;
		cout << "�������� ������ �Է��Ͻÿ� " << endl;
		cout << "�̸� : ";
		cin >> student.name;
		cout << "�������� �ν�Ÿ ���̵� �Է��Ͻÿ� : ";
		cin >> student.insta_ID;
		while (true) {
			try
			{
				cout << "�������� ������ �Է��Ͻÿ� (������ ��� 0, ������ ��� 1): ";
				cin >> student.gender;
				if (student.gender != 0 && student.gender != 1) {
					throw invalid_argument("0 �Ǵ� 1�� �Է��ϼ���");
				}
			}
			catch (exception& e) {
				cout << "���� : " << e.what() << endl;
			}
			if (student.gender == 0 || student.gender == 1) {
				break;
			}
			cout << endl;
			count++;

			if (count == 10) {
				cout << "��Ī�� ���� �ּ����� �ο��� ��� ä�������ϴ� ��� �ο��� �߰��Ͻðڽ��ϱ�?(O/X) :";
				cin >> OX;

				if (OX != 'o' && OX != 'O') {
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
			Profiles.push_back(student);
		}
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
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (i == 4) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		//�׽�Ʈ�� ���� �ڵ�
		cout << endl;


		int answerCount2[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� " << "(�ſ� �ƴϴ�=1, �ƴϴ�=2, ����=3, �׷���=4, �ſ� �׷���=5)" << endl;

			cout << conflict[i] << endl;

			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
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
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
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
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
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
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount5[answer - 1]++;
			if (i == 4) {
				Profiles[k].proportion = answerCount5[0] * (-5) + answerCount5[1] * (-3) + answerCount5[3] * 3 + answerCount5[4] * 5;


			}
		}



	}//�̰� �˻��ϴ� ��ü for���� ��ȣ
	//���ϴ� ���� ���� �ű�� ��Ī���� Ȯ��
	cout << Profiles[0].count << endl;

	cout << "��Ī ��� �м����Դϴ�" << endl;

	int Mvalue = numeric_limits<int>::max(); // �ʱⰪ�� ������ �ִ밪���� ����


	// ���� ���� focal ���� ���� �� �л��� ������ ����
	Student minFocalStudent1, minFocalStudent2;

	// ��� �л��鿡 ���� ���� ����
	for (int i = 0; i < size(Profiles); ++i) {
		for (int j = i + 1; j < size(Profiles); ++j) {
			// i�� j �л��� ���� ���� ����
			Student result = Profiles[i] - Profiles[j];


			if (result.focal + result.conflict + result.mind + result.date + result.proportion < Mvalue) {
				Mvalue = result.value;
				minFocalStudent1 = Profiles[i];
				minFocalStudent2 = Profiles[j];
			}
		}
	}

	// ��� ���

	cout << "���� Ŀ���� �� �� �ִ� �л� 1: ";
	minFocalStudent1.Print_Profile();
	cout << "���� Ŀ���� �� �� �ִ� �л� 2: ";
	minFocalStudent2.Print_Profile();


	cout << "���� �ο� ������ �˷��帮�ڽ��ϴ�" << endl;

	ifstream is{ "Rate Score.txt" }; // ���ϸ� .txt Ȯ���ڸ� ����ϴ� ���� �Ϲ����Դϴ�.
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

