#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

class Sieve {
public:
    int maximumValue; // �ִ밪�� �����ϴ� ����
    vector<bool> isPrime; // �Ҽ� ���θ� �����ϴ� �迭

    // �����佺�׳׽��� ü ������
    Sieve(int maximumValue) {
        this->maximumValue = maximumValue; // �ִ밪 �ʱ�ȭ
        this->isPrime.assign(maximumValue + 1, true); // ��� ���� �Ҽ��� �����Ͽ� �ʱ�ȭ
        this->fillSieve(); // �����佺�׳׽��� ü �˰����� ȣ���Ͽ� �Ҽ��� �Ǻ�
    }

    // num�� �Ҽ����� ���θ� ��ȯ�ϴ� �Լ�
    bool isPrimeNumber(int num) const {
        return this->isPrime[num];
    }

    // �����佺�׳׽��� ü �˰����� �̿��Ͽ� �Ҽ��� �Ǻ��ϴ� �Լ�
    void fillSieve() {
        this->isPrime[0] = this->isPrime[1] = false; // 0�� 1�� �Ҽ��� �ƴϹǷ� false�� ����

        // 2���� �����Ͽ� maximumValue ������ ���� ���� �Ҽ� �Ǻ��� ����
        for (int num = 2; num * num <= maximumValue; num += 1) {
            if (isPrime[num]) { // num�� �Ҽ��� ��쿡�� ����
                // num�� ������� ��� �Ҽ��� �ƴ� ������ ǥ��
                for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) {
                    int index = (int)mul; // ����� �ε��� ���
                    isPrime[index] = false; // �Ҽ��� �ƴ� ���� ǥ��
                }
            }
        }
    }

    // ���� ���� �Ҽ��� ã�� ��ȯ�ϴ� �Լ�
    vector<int> getAllPrimeNumbers(int from, int to) {
        vector<int> primes; // �Ҽ��� �����ϴ� �迭

        // ���� ���� ��� ���� ���� �Ҽ� ���θ� �Ǻ��Ͽ� primes �迭�� ����
        for (int num = from; num <= to; num += 1) {
            if (isPrimeNumber(num)) { // num�� �Ҽ��� ���
                primes.push_back(num); // primes �迭�� �Ҽ� �߰�
            }
        }
        return primes; // ã�� �Ҽ��� ��ȯ
    }
};

int main() {
    const int MAX_VALUE = 1000000; // �ִ밪 ��� ����
    Sieve sieve = Sieve(MAX_VALUE); // �ִ밪���� �ʱ�ȭ�� �����佺�׳׽��� ü ��ü ����

    int caseSize; // �Է� ���̽� ������ �����ϴ� ����
    scanf("%d", &caseSize); // �Է� ���̽� ������ �Է� ����

    vector<pair<int, int>> line; // �Է¹����� �����ϴ� ����

    // �Է� ���̽��� ������ �Է� �޾� line ���Ϳ� ����
    for (int i = 0; i < caseSize; ++i) {
        int L, R;
        scanf("%d %d", &L, &R); // ������ �Է� ����
        line.push_back(make_pair(L, R)); // ������ line ���Ϳ� �߰�
    }

    // ��� �Է¹����� ���� ����� ���
    for (int caseIndex = 0; caseIndex < caseSize; ++caseIndex) {
        int L = line[caseIndex].first; // �Է¹����� ���� ����
        int R = line[caseIndex].second; // �Է¹����� �� ����

        // getAllPrimeNumbers �Լ��� ��ü�� ���� ȣ���Ͽ� �Ҽ��� ã��
        vector<int> allPrimeNumbers = sieve.getAllPrimeNumbers(L, R);

        // ��� ���
        printf("case#%d:\n", caseIndex + 1); // ���� ���̽��� �ε����� ���
        printf("%d\n", (int)allPrimeNumbers.size()); // ã�� �Ҽ��� ������ ���
    }

    return 0; // ���α׷� ����
}