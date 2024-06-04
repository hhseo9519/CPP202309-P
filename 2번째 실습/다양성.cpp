#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;

// �迭���� ���� �ٸ� ������ ������ ���� �Լ�
int getElementTypeCount(int data[], int n)
{
	int countType = 0; // ���� �ٸ� ������ ������ �����ϴ� ����

	for (int i = 1; i < n; i++) // for���� ���� �迭�� �ε��� ������ �񱳸� �ݺ�
	{
		if (data[i - 1] != data[i]) // ���ҵ��� ������������ �Ǿ��ֱ� ������ ������ҿ� �������Ҹ� ���Ͽ� �ٸ���츦 üũ�ϸ� ���δٸ� ������ ������ �˾Ƴ��°��� �����ϴ�.
		{
			countType++; // ���� �ٸ� ������ ���� ����
		}
	}

	return countType; // ���� �ٸ� ������ ���� ��ȯ
}

int main()
{
	int n;
	int* data; // ������ȣ �迭�� ������ ������ ����

	scanf("%d", &n); // �迭�� ũ�� �Է�

	data = new int[n]; // �迭 ���� �Ҵ�

	// �迭�� ���� �Է¹޾� data�迭�� ����
	for (int i = 0; i < n; i++)
	{
		scanf("%d\n", &data[i]);
	}

	// ���� �ٸ� ������ ������ ����
	int answer = getElementTypeCount(data, n);

	printf("%d\n", answer); // ��� ���

	delete[] data; // ���� �Ҵ�� �迭 �޸� ����
	return 0;
}