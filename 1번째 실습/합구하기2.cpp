#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void solve(int data[], int n, int p, int q)
{
	int count = 0;// �� Ż �� �ִ� ��� ���� �������� ���� ����
	int weight_sum = 0;// Ż �� �ִ� ������� �������� ���� �����ϱ� ���� ���� ����
	for (int i = 0; i < n; i++)// main �Լ����� �Է¹��� �����͵��� �̿��Ͽ� ���� count,weight_sum�� ������Ʈ �Ѵ�
	{
		if (data[i] <= p)// ������ �Ǵ� ������ p���� ���� ��� count�� 1�� ����, weight_sum�� �ش� �ε��� ���� ���Ͽ� ������ ����.
		{
			count++;
			weight_sum += data[i];
		}
	}
	printf("%d %d \n", count, weight_sum); //��� ���Ŀ� �°� count�� weight_sum�� ���
	if (weight_sum <= q)//weight_sum�� q���� ������� ��� �Բ� ž�� �����ϹǷ� YES�� ���, �ƴѰ�� NO�� ��� 
	{
		printf("YES \n");
	}
	else {
		printf("NO \n");
	}
}
int main() {
	int n, p, q; // n: ����� ��, p: ���� ������, q: ���Ǵ� �ִ� �� ������
	int* data; // ������� �����Ը� ������ ���� �迭�� ������

	// ����� ��, ���� ������, ���Ǵ� �ִ� �� �����Ը� �Է¹޽��ϴ�.
	scanf("%d %d %d", &n, &p, &q);

	data = new int[n]; // n ũ���� ���� �迭 �Ҵ��մϴ�.

	// �� ������� �����Ը� �Է¹޾� �迭�� �����մϴ�.
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	// solve �Լ��� ȣ���Ͽ� ������ �ذ��մϴ�.
	solve(data, n, p, q);

	delete[] data; // �������� �Ҵ�� �޸𸮸� ��ȯ�մϴ�.
	return 0; // ���α׷� ����
}