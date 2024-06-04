#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// �� �ȿ� ���ԵǴ��� ���θ� �Ǵ��ϴ� �Լ�
bool isInseide(long long x, long long y, long long R) {
    long long sqd = x * x + y * y; // x, y ��ǥ�� ���� �Ÿ� ���
    if (sqd < R * R) { // ���� �Ÿ��� �������� �������� ������ �� �ȿ� ���Ե�
        return true;
    }
    return false;
}

// �������� ���� ���� ��� �Լ�
long long testcase(long long R) {
    long long sum = 0; // �� �ȼ� ���� ������ ����
    long long y = R; // �ʱ� y ��ǥ�� ���������� ����
    // 1��и� ������ x ��ǥ�� ������Ű�鼭 Ž��
    for (long long x = 0; x <= R; x++) {
        long long height = 0; // ���� x ��ǥ������ ����
        // y ��ǥ�� �������鼭 �� ���ο� �ִ��� Ȯ��
        for (; y >= 0; y--) {
            if (isInseide(x, y, R)) { // �� ���ο� �ִ� ���
                height = (y + 1); // ���� ���� ����
                break; // ���ο� ������ �� ������ �ʿ� ����
            }
        }
        sum += height; // ���� x ��ǥ������ ���̸� �� �ȼ� ���� �߰�
    }
    return sum * 4; // 1��и鿡�� ����� ������ 4���Ͽ� ��ü �������� Ȯ��
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // ���̽� �� �Է� �ޱ�
    vector<long long> radiuses(caseSize); // �������� ������ ���� ����

    // ������ �Է� �ޱ�
    for (int i = 0; i < caseSize; i++) {
        scanf("%lld", &radiuses[i]);
    }

    // ��� ���
    for (int i = 0; i < caseSize; i++) {
        long long area = testcase(radiuses[i]); // �ش� �������� ���� ���� ���
        printf("#%d\n%lld\n", i + 1, area); // ��� ���
    }

    return 0;
}