#define _CRT_SECURE_NO_WARNINGS // Visual Studio���� scanf ��� ���� ��� �����ϱ� ���� ��ó�� ���ù�

#include <cstdio> // C ǥ�� ����� ���̺귯��
#include <vector> // C++ ǥ�� ���̺귯���� vector ����

using namespace std; // ǥ�� ���̺귯�� �Լ��� ��ü�� std::�� ������ �ʰ� ����ϱ� ���� using ���ù�

const int MAX_N = 1000000; // ������ �ִ� n ��

vector<int> FIBONACCI_TABLE; // �Ǻ���ġ ������ ������ ���� ����

// �Ǻ���ġ ������ �����ϴ� �Լ�
vector<int> makeFibonacciTable(int n) {
    const int MOD = 100000000; // ������ ��

    vector<int> ret(n + 1); // ��� ���� �ʱ�ȭ
    ret[1] = 0; // �ʱⰪ ����
    ret[2] = 1; // �ʱⰪ ����

    // �Ǻ���ġ ���� ����
    for (int i = 3; i <= n; ++i) {
        ret[i] = ret[i - 1] + ret[i - 2]; // ���� ���� ���� �� ���� ��
        ret[i] %= MOD; // MOD�� ���� ������ ����
    }

    return ret; // �Ǻ���ġ ���� ��ȯ
}

// n��° �Ǻ���ġ ���� ��ȯ�ϴ� �Լ�
int getFibo(int n) {
    int answer = FIBONACCI_TABLE[n]; // ���� ���Ϳ� ����� �Ǻ���ġ �������� n��° �� ��������
    return answer; // ��� ��ȯ
}

// ���� �Լ�
int main() {
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N); // �ִ� n������ �Ǻ���ġ ���� �����Ͽ� ���� ���Ϳ� ����

    int caseSize;
    scanf("%d", &caseSize); // �׽�Ʈ ���̽� ���� �Է�

    // �׽�Ʈ ���̽� ó��
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        int n;
        scanf("%d", &n); // n �� �Է�

        int answer = getFibo(n); // n��° �Ǻ���ġ �� ���ϱ�
        printf("%d\n", answer); // ��� ���
    }

    FIBONACCI_TABLE.clear(); // �Ǻ���ġ ������ ������ ���� ���� ����

    return 0; // ���α׷� ����
}