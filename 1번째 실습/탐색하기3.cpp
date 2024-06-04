#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int findIndex(int data[], int n)
{
	int sum = 0, x = 0;// ������ �����ϴ� ����sum�� �ε����� ���� ���� �� ���� x�� �����մϴ�.
	for (int i = 0; i < n; i++) {
		sum += data[i];//��հ��� �Ÿ��̹Ƿ� ����� ���ϱ� ���� ���� sum�� ���ؾ� �ϰ�, sum�� data�迭�� ������ �����ؼ� �����ݴϴ�.
	}
	for (int i = 0; i < n; i++) {
		int dx = abs(n * data[x] - sum);//�������� ������� �ʱ� ���� �� �׿� n���� ������ ���� ������ dx�� �����մϴ�.
		int di = abs(n * data[i] - sum);//�������� ������� �ʱ� ���� �� �׿� n���� ������ ���� ������ di�� �����մϴ�.
		if (dx > di) {
			x = i; //���� dx�� di���� ũ�ٸ� x�� i�� �����Ͽ� �Ÿ��� �� ���� ���� �ε����� x�� �����մϴ�.
		}
	}
	return x + 1;//���� ��ȣ�� 1���� �����ϱ� ������ x+1�� ��ȯ�մϴ�.
}
int main() {
    int n; // �迭�� ũ�⸦ ������ ����
    int* data; // �������� �Ҵ�� �迭�� ����Ű�� ������

    scanf("%d", &n); // �迭�� ũ�⸦ �Է¹޽��ϴ�.

    data = new int[n]; // �迭�� ũ�⿡ �°� �������� �޸𸮸� �Ҵ��մϴ�.

    // ����ڷκ��� �迭�� �� ��Ҹ� �Է¹޽��ϴ�.
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // findIndex �Լ��� ȣ���Ͽ� ���� �ε����� ã��, �ش� �ε����� �ش� ��Ҹ� ����մϴ�.
    int answer = findIndex(data, n);
    printf("%d %d\n", answer, data[answer - 1]); // ���� �ε����� 0���� �������� �����Ƿ� 1�� ���� ����մϴ�.

    delete[] data; // �������� �Ҵ�� �޸𸮸� ��ȯ�մϴ�.
    return 0; // ���α׷� ����
}
