#include<iostream>
#include<vector>
#include<string>
#include <iterator>
#include"program.h"
using namespace std;
int Check_Score(vector a) {//r�׳� �迭�� �����ϸ� �� �� ������

}

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
	while (true)
	{

		Student student;
		cout << "�������� ������ �Է��Ͻÿ� " << endl;
		cout << "�̸� : ";
		cin >> student.name;
		cout << "�������� �ν�Ÿ ���̵� �Է��Ͻÿ� : ";
		cin >> student.insta_ID;
		cout << "�������� ������ �Է��Ͻÿ� (������ ��� 0, ������ ��� 1)";
		cin >> student.gender;
		while (student.gender != 0 && student.gender != 1) {
			cout << "�ٽ� �Է����ּ��� (������ ��� 0, ������ ��� 1)";
			cin >> student.gender;
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

		vector<int> answerCount(5, 0); // 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� ����
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� ";
			cout << " ";//���⿡�ٰ� �� �������� �Լ��� ������ �迭�� ���Ƽ� ���� ����ٰ� �ۼ����� �ʰ� ������;" �迭[i]&&&&
			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].conflict = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� ����
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� ";
			cout << " ";//���⿡�ٰ� �� �������� �Լ��� ������ �迭�� ���Ƽ� ���� ����ٰ� �ۼ����� �ʰ� ������;" �迭[i]&&&&
			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].focal = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� ����
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� ";
			cout << " ";//���⿡�ٰ� �� �������� �Լ��� ������ �迭�� ���Ƽ� ���� ����ٰ� �ۼ����� �ʰ� ������;" �迭[i]&&&&
			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].mind = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� ����
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� ";
			cout << " ";//���⿡�ٰ� �� �������� �Լ��� ������ �迭�� ���Ƽ� ���� ����ٰ� �ۼ����� �ʰ� ������;" �迭[i]&&&&
			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].date = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}
		vector<int> answerCount(5, 0); // 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� ����
		// ������ �亯 �ޱ�
		for (int i = 0; i < 5; ++i) {

			cout << "���� " << i + 1 << " �� ";
			cout << " ";//���⿡�ٰ� �� �������� �Լ��� ������ �迭�� ���Ƽ� ���� ����ٰ� �ۼ����� �ʰ� ������;" �迭[i]&&&&
			int answer;
			cin >> answer;

			// ��ȿ�� �亯���� Ȯ��
			while (answer < 1 || answer > 5) {
				cout << "�ٽ� �Է����ּ��� (1~5 ������ ����): ";
				cin >> answer;
			}

			// �� �亯�� ���� ���� ����
			answerCount[answer - 1]++;
			if (count == 4) {
				Profiles[k].proportion = answerCount[0] * (-5) + answerCount[1] * (-3) + answerCount[3] * 3 + answerCount[4] * 5;

			}
		}

	}//�̰� �˻��ϴ� ��ü for���� ��ȣ

}// <----�̰� int main�� ��ȣ
