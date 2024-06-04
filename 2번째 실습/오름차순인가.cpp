#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;

// �迭�� ������������ ���ĵǾ� �ִ��� Ȯ���ϴ� �Լ�
bool isOrdered(int data[], int n)
{
	int count = 0; // ������ �� ��Ұ� ������������ �迭�Ǿ��ִ��� Ȯ���� �� ����� ���� ����

	// for���� ���� ������ �� ��Ҹ� ��
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] > data[i + 1]) // ���� ��Ұ� ���� ��Һ��� ū ���
		{
			count++; // count ���� 1����
			break; // ���������� �ƴ϶�� ���̻� Ȯ�� �� �ʿ� ���� break�� �ݺ��� ����
		}
	}

	if (count > 0) // count�� 0���� ū, �� ���������� �ƴѰ��
	{
		return false; // ���������� �ƴ��� ��ȯ
	}
	else // ������ ���, ���������� ���
	{
		return true; // ������������ ��ȯ
	}
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n); // �迭�� ũ�� �Է�

	data = new int[n]; // �迭 ���� �Ҵ�

	// �迭 ��� �Է�
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	// isOrdered �Լ��� ���� �迭�� ������������ ���ĵǾ� �ִ��� Ȯ��
	bool result = isOrdered(data, n);

	// ��� ���
	if (result) // ���������� ��� YES���
	{
		printf("YES");
	}
	else // ���������� �ƴ� ��� NO���
	{
		printf("NO");
	}

	delete[] data; // ���� �Ҵ�� �迭 �޸� ����
	return 0;
}