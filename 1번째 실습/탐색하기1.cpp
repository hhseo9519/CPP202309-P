#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

int findIndex(int data[], int n, int m) {
	int index = -1;//ã���� �ϴ� ���� �ε����� ����ϱ� ���� ���� ����, ã���� �ϴ� ���� �迭�� ���ٸ� -1�� ��ȯ�ؾ� �ϹǷ� -1�� �ʱ�ȭ�մϴ�.
	for (int i = 0; i < n; i++)
	{
		if (data[i] == m)//ã���� �ϴ� ���� m�� ���� ���� �����ϴ� �迭�� �ε����� ã���� index������ �����մϴ�.
		{
			index = i;
		}
	}
	return index;//index�� ��ȯ�մϴ�.
}
int main() {
    int n, m; // ���� n�� m�� �����Ͽ� �Է��� ������ ������ ã�� �� m�� ������ ������ ����մϴ�.
    int* data; // �������� �Ҵ�� ���� �迭�� ����Ű�� ������ ���� data�� �����մϴ�.

    // ����ڷκ��� n�� m�� ���� �Է¹޽��ϴ�.
    scanf("%d %d", &n, &m);

    // ���̰� n�� ���� �迭�� �������� �Ҵ��Ͽ� data�� �Ҵ��մϴ�.
    data = new int[n];

    // ����ڷκ��� n���� ������ �Է¹޾� data �迭�� �����մϴ�.
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // findIndex �Լ��� ȣ���Ͽ� �迭 data���� �� m�� �ε����� ã���ϴ�.
    int answer = findIndex(data, n, m);

    // ã�� �ε����� ����մϴ�.
    printf("%d\n", answer);

    // �������� �Ҵ�� �޸𸮸� ��ȯ�մϴ�.
    delete[] data;
    return 0;
}