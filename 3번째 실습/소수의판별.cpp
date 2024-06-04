#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

// �־��� ������ �Ҽ����� �Ǻ��ϴ� �Լ�
bool isPrime(int N) {
    if (N <= 1) { // �־��� ���� 1 �����̸� �Ҽ��� �ƴ�
        return false;
    }
    for (int i = 2; i * i <= N; i++) { // 2���� N�� �����ٱ��� �ݺ�
        if (N % i == 0) { // ������ �������� �Ҽ��� �ƴ�
            return false;
        }
    }
    return true; // ������ �������� ������ �Ҽ�
}

// �׽�Ʈ ���̽��� ó���ϴ� �Լ�
void testcase(int caseIndex) {
    int n;
    scanf("%d", &n); // �Է� �ޱ�

    bool result = isPrime(n); // �Ҽ����� �Ǻ�

    printf("Case #%d\n", caseIndex); // ���̽� ��ȣ ���

    if (result) {
        printf("YES\n"); // �Ҽ��� ���
    }
    else {
        printf("NO\n"); // �Ҽ��� �ƴ� ���
    }
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // �׽�Ʈ ���̽� ���� �Է� �ޱ�
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
        testcase(caseIndex); // �� �׽�Ʈ ���̽� ó��
    }
    return 0;
}