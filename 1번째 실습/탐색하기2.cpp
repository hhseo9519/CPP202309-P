#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
void printIndexes(string school[], int n)
{
	int first = -1;
	int last = -1;//ù��°�� ������ ���ִ��б� �л��� �ε����� ������ first�� last������ ����
	for (int i = 0; i < n; i++)// AJOU���б� �л����� �ε����� ã�� ���� �ݺ��� ����
	{
		if (school[i]== "AJOU")// �迭 school�� �ش� �ε����� ����Ǿ��ִ� ���ڿ��� AJOU�� ���ٸ� �Ʒ� ���� ����
		{
			if (first == -1)//���� if���� ������ ���� �ϸ鼭 first�� -1�϶� first�� i+1�� ����
				first = i + 1;
			last = i + 1;//�迭 school�� �ش� �ε����� ����Ǿ��ִ� ���ڿ��� AJOU�� ������ first�� -1�� �ƴҶ� ����
		}
	}
	printf("%d %d\n", first, last);// ��� ���Ŀ� �°� first�� last�� ���
}
int main() {
    int n; // �л� ���� ������ ����
    char buff[11]; // ���ڿ��� �Ͻ������� ������ �迭 (���ڿ��� �ִ� 10���� + �� ���� '\0'�� ����� ũ�⸦ 11�� ����)
    string* school; // �б����� ������ ���� ���ڿ� �迭�� ������

    scanf("%d", &n); // ����ڷκ��� �л� ���� �Է¹���

    school = new string[n]; // �л� ���� ���� �������� ���ڿ� �迭 �Ҵ�

    // �л��� �б����� �Է¹޾� school �迭�� ����
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buff); // ���ڿ��� �Է¹޾� buff �迭�� ����
        school[i] = buff; // buff�� ����� ���ڿ��� school �迭�� ����
    }

    // �Լ��� ȣ���Ͽ� ���ִ��б� �л����� �ε����� ���
    printIndexes(school, n);

    delete[] school; // �������� �Ҵ�� �޸� ��ȯ
    return 0; // ���α׷� ����
}