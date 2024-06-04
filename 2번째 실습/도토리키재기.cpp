#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;

// ���丮�� Ű�� ������ �Է� �ް� Ư�� �޿� �ش��ϴ� ���丮�� �ִ� Ű�� ��ȯ�ϴ� �Լ�
int getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxHeight = -1;//���� ��� -1�� ����ؾ��ϱ� ������ -1�� �ʱ�ȭ
	for (int i = n - 1; i >= 0; i--) //Ű�� ������������ ���ֱ� ������ �ڿ������� ã�°��� ���귮�� �־� ȿ������
	{
		if (month[i] == m)//�Է� ���� ���� ���� ���� ���丮�� ���� ���� ���� ��츦 üũ
		{
			maxHeight = height[i];//������ ��ġ�ϴ� ��쿡 �ش� ���丮�� Ű�� �ִ�Ű�� ����
			break; //�̹� ���ϴ� ���丮�� ã�����Ƿ� break�� ���� ����ġ�⸦ �� �� �ִ�.
		}
	}
	return maxHeight; //maxHeight�� ��ȯ


}

int main()
{
	int n, m;
	int* height; // ���丮�� Ű �迭 ������
	int* month; // ���丮�� ���� �� �迭 ������

	scanf("%d", &n); // ���丮�� �� �Է�

	// ���丮�� Ű�� ���� ������ ������ �迭 ���� �Ҵ�
	height = new int[n];
	month = new int[n];

	// �� ���丮�� Ű�� �Է¹޾� height�迭�� ����
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &height[i]);
	}

	// �� ���丮�� ������ �Է¹޾� month�迭�� ����
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m); // ���� �� �Է�

	// �Էµ� ������ �������� ���� �޿� �ش��ϴ� ���丮�� �ִ� Ű�� ����
	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer); // �ִ� Ű ���

	delete[] height; // ���� �Ҵ�� �޸� ����
	delete[] month;
	return 0;
}