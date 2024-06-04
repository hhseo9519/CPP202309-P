#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

class Sieve {
public:
    int maximumValue; // 최대값을 저장하는 변수
    vector<bool> isPrime; // 소수 여부를 저장하는 배열

    // 에라토스테네스의 체 생성자
    Sieve(int maximumValue) {
        this->maximumValue = maximumValue; // 최대값 초기화
        this->isPrime.assign(maximumValue + 1, true); // 모든 수를 소수로 가정하여 초기화
        this->fillSieve(); // 에라토스테네스의 체 알고리즘을 호출하여 소수를 판별
    }

    // num이 소수인지 여부를 반환하는 함수
    bool isPrimeNumber(int num) const {
        return this->isPrime[num];
    }

    // 에라토스테네스의 체 알고리즘을 이용하여 소수를 판별하는 함수
    void fillSieve() {
        this->isPrime[0] = this->isPrime[1] = false; // 0과 1은 소수가 아니므로 false로 설정

        // 2부터 시작하여 maximumValue 이하의 수에 대해 소수 판별을 수행
        for (int num = 2; num * num <= maximumValue; num += 1) {
            if (isPrime[num]) { // num이 소수인 경우에만 실행
                // num의 배수들을 모두 소수가 아닌 것으로 표시
                for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) {
                    int index = (int)mul; // 배수의 인덱스 계산
                    isPrime[index] = false; // 소수가 아닌 수로 표시
                }
            }
        }
    }

    // 범위 내의 소수를 찾아 반환하는 함수
    vector<int> getAllPrimeNumbers(int from, int to) {
        vector<int> primes; // 소수를 저장하는 배열

        // 범위 내의 모든 수에 대해 소수 여부를 판별하여 primes 배열에 저장
        for (int num = from; num <= to; num += 1) {
            if (isPrimeNumber(num)) { // num이 소수인 경우
                primes.push_back(num); // primes 배열에 소수 추가
            }
        }
        return primes; // 찾은 소수를 반환
    }
};

int main() {
    const int MAX_VALUE = 1000000; // 최대값 상수 정의
    Sieve sieve = Sieve(MAX_VALUE); // 최대값으로 초기화된 에라토스테네스의 체 객체 생성

    int caseSize; // 입력 케이스 개수를 저장하는 변수
    scanf("%d", &caseSize); // 입력 케이스 개수를 입력 받음

    vector<pair<int, int>> line; // 입력범위를 저장하는 벡터

    // 입력 케이스의 범위를 입력 받아 line 벡터에 저장
    for (int i = 0; i < caseSize; ++i) {
        int L, R;
        scanf("%d %d", &L, &R); // 범위를 입력 받음
        line.push_back(make_pair(L, R)); // 범위를 line 벡터에 추가
    }

    // 모든 입력범위에 대해 결과를 출력
    for (int caseIndex = 0; caseIndex < caseSize; ++caseIndex) {
        int L = line[caseIndex].first; // 입력범위의 시작 범위
        int R = line[caseIndex].second; // 입력범위의 끝 범위

        // getAllPrimeNumbers 함수를 객체를 통해 호출하여 소수를 찾음
        vector<int> allPrimeNumbers = sieve.getAllPrimeNumbers(L, R);

        // 결과 출력
        printf("case#%d:\n", caseIndex + 1); // 현재 케이스의 인덱스를 출력
        printf("%d\n", (int)allPrimeNumbers.size()); // 찾은 소수의 개수를 출력
    }

    return 0; // 프로그램 종료
}