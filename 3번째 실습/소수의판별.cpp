#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

// 주어진 정수가 소수인지 판별하는 함수
bool isPrime(int N) {
    if (N <= 1) { // 주어진 수가 1 이하이면 소수가 아님
        return false;
    }
    for (int i = 2; i * i <= N; i++) { // 2부터 N의 제곱근까지 반복
        if (N % i == 0) { // 나누어 떨어지면 소수가 아님
            return false;
        }
    }
    return true; // 나누어 떨어지지 않으면 소수
}

// 테스트 케이스를 처리하는 함수
void testcase(int caseIndex) {
    int n;
    scanf("%d", &n); // 입력 받기

    bool result = isPrime(n); // 소수인지 판별

    printf("Case #%d\n", caseIndex); // 케이스 번호 출력

    if (result) {
        printf("YES\n"); // 소수인 경우
    }
    else {
        printf("NO\n"); // 소수가 아닌 경우
    }
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 개수 입력 받기
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
        testcase(caseIndex); // 각 테스트 케이스 처리
    }
    return 0;
}