#include<iostream>
#include<vector>
#include<string>
#include <iterator>
#include"program.h"
using namespace std;

int main() {
	//���α׷� ���� ��û�ޱ�
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
	string strArray[6] = { "q1", "q2", "q3", "q4", "q5", "q6" };
	while (true)
	{

		Student student;
		cout << "�������� ������ �Է��Ͻÿ� " << endl;
		cout << "�̸� : ";
		cin >> student.name;
		cout << "�������� �ν�Ÿ ���̵� �Է��Ͻÿ� : ";
		cin >> student.insta_ID;
		while (true) {
			cout << "�������� ������ �Է��Ͻÿ� (������ ��� 0, ������ ��� 1): ";
			cin >> student.gender;
			if (cin.fail()) {
				cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else if (student.gender == 0 || student.gender == 1) {
				break;
			}
			else {
				cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1�� �Է��ϼ���." << endl;
			}
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
	int FINISH_TEST = 0;
	int num = 0;
	for (int k = 0; k < size(Profiles); k++) {

		int answerCount[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 6; ++i) {

			cout << "���� " << i + 1 << " �� " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if ( i== 5) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		//�׽�Ʈ�� ���� �ڵ�
		cout << endl;
		cout << "�׽�Ʈ �� :" << Profiles[0].focal << endl;

		int answerCount2[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 6; ++i) {

			cout << "���� " << i + 1 << " �� " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount2[answer - 1]++;
			if (i==5) {
				Profiles[k].conflict = answerCount2[0] * (-5) + answerCount2[1] * (-3) + answerCount2[3] * 3 + answerCount2[4] * 5;

			}
		}
		int answerCount3[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 6; ++i) {

			cout << "���� " << i + 1 << " �� " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount3[answer - 1]++;
			if (i == 5) {
				Profiles[k].mind = answerCount3[0] * (-5) + answerCount3[1] * (-3) + answerCount3[3] * 3 + answerCount3[4] * 5;

			}
		}
		int answerCount4[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 6; ++i) {

			cout << "���� " << i + 1 << " �� " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount4[answer - 1]++;
			if (i== 5) {
				Profiles[k].date = answerCount4[0] * (-5) + answerCount4[1] * (-3) + answerCount4[3] * 3 + answerCount4[4] * 5;

			}
		}
		int answerCount5[5] = { 0 };
		// ������ �亯 �ޱ�
		for (int i = 0; i < 6; ++i) {

			cout << "���� " << i + 1 << " �� " << endl;

			cout << strArray[i] << endl;

			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount5[answer - 1]++;
			if (i == 5) {
				 Profiles[k].proportion = answerCount5[0] * (-5) + answerCount5[1] * (-3) + answerCount5[3] * 3 + answerCount5[4] * 5;


			}
		}


	}//�̰� �˻��ϴ� ��ü for���� ��ȣ

}// <----�̰� int main�� ��ȣ