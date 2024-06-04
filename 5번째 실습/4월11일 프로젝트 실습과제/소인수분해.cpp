#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

// 소인수분해 함수
vector<long long> factorize(long long n) {
    vector<long long> factors; // 소인수를 저장할 벡터

    // 소인수분해를 수행
    for (long long div = 2; div * div <= n; div += 1) {
        while (n % div == 0) {
            factors.push_back(div);
            n /= div;
        }
    }
    // 남은 수가 1보다 크면 소인수로 남은 수를 추가
    if (n > 1) {
        factors.push_back(n);
    }
    return factors; // 소인수 벡터 반환
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // 입력의 개수를 받음

    vector<long long> inputs; // 입력 값을 저장할 벡터
    for (int i = 0; i < caseSize; ++i) {
        long long n;
        scanf("%lld", &n); // 각 입력을 받아서 벡터에 저장
        inputs.push_back(n);
    }

    // 입력에 대해 각각 소인수분해를 수행하고 결과를 출력
    for (int i = 0; i < inputs.size(); ++i) {
        vector<long long> factors = factorize(inputs[i]); // 소인수분해 수행
        printf("#%d:\n", i + 1); // 결과 출력 시 인덱스는 1부터 시작
        for (int j = 0; j < factors.size(); ++j) {
            if (j > 0) {
                printf(" ");
            }
            printf("%lld", factors[j]); // 각 소인수를 출력
        }
        printf("\n");
    }

    return 0;
}