#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

// ���μ����� �Լ�
vector<long long> factorize(long long n) {
    vector<long long> factors; // ���μ��� ������ ����

    // ���μ����ظ� ����
    for (long long div = 2; div * div <= n; div += 1) {
        while (n % div == 0) {
            factors.push_back(div);
            n /= div;
        }
    }
    // ���� ���� 1���� ũ�� ���μ��� ���� ���� �߰�
    if (n > 1) {
        factors.push_back(n);
    }
    return factors; // ���μ� ���� ��ȯ
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // �Է��� ������ ����

    vector<long long> inputs; // �Է� ���� ������ ����
    for (int i = 0; i < caseSize; ++i) {
        long long n;
        scanf("%lld", &n); // �� �Է��� �޾Ƽ� ���Ϳ� ����
        inputs.push_back(n);
    }

    // �Է¿� ���� ���� ���μ����ظ� �����ϰ� ����� ���
    for (int i = 0; i < inputs.size(); ++i) {
        vector<long long> factors = factorize(inputs[i]); // ���μ����� ����
        printf("#%d:\n", i + 1); // ��� ��� �� �ε����� 1���� ����
        for (int j = 0; j < factors.size(); ++j) {
            if (j > 0) {
                printf(" ");
            }
            printf("%lld", factors[j]); // �� ���μ��� ���
        }
        printf("\n");
    }

    return 0;
}