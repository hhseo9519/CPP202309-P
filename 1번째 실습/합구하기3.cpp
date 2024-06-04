#define _CRT_SECURE_NO_WARNINGS // �����Ϸ����� ���� ��� �����ϱ� ���� ����

#include <cstdio> // C ǥ�� ����� ��� ����
#include <iostream> // C++ ǥ�� ����� ��� ����

using namespace std; // std ���ӽ����̽��� ���

// 1���� i������ ���� ��ȯ�ϴ� �Լ�
int getRangeSumFromOne(int i) {
    int answer = 0;
    for (int j = 0; j <= i; j++) {
        answer += j;
    }
    return answer;
}

// 0���� N������ ������ 1���� i������ ���� ���� �� ��� ���� ���� ��ȯ�ϴ� �Լ�
long long getAnswer(int N) {
    long long answer = 0; // ���� ������ ���� ���� �� �ʱ�ȭ
    for (int i = 0; i <= N; i++) { // 0���� N���� �ݺ�
        int rangesum = getRangeSumFromOne(i); // 1���� i������ �� ���
        answer += rangesum; // ���� ���� ��ü �信 ����
    }
    return answer; // ��ü �� ��ȯ
}

int main() {
    int n;

    scanf("%d", &n); // ����ڷκ��� ���� �Է� ����

    long long answer = getAnswer(n); // getAnswer �Լ� ȣ���Ͽ� �� ���

    printf("%lld\n", answer); // ���� ���� ���

    return 0; 
}