#include<iostream>
#include<vector>
#include<string>
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
	
}
