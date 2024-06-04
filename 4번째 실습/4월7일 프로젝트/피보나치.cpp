#define _CRT_SECURE_NO_WARNINGS // Visual Studio에서 scanf 사용 관련 경고를 억제하기 위한 전처리 지시문

#include <cstdio> // C 표준 입출력 라이브러리
#include <vector> // C++ 표준 라이브러리의 vector 포함

using namespace std; // 표준 라이브러리 함수와 객체를 std::를 붙이지 않고 사용하기 위한 using 지시문

const int MAX_N = 1000000; // 가능한 최대 n 값

vector<int> FIBONACCI_TABLE; // 피보나치 수열을 저장할 전역 벡터

// 피보나치 수열을 생성하는 함수
vector<int> makeFibonacciTable(int n) {
    const int MOD = 100000000; // 나누는 수

    vector<int> ret(n + 1); // 결과 벡터 초기화
    ret[1] = 0; // 초기값 설정
    ret[2] = 1; // 초기값 설정

    // 피보나치 수열 생성
    for (int i = 3; i <= n; ++i) {
        ret[i] = ret[i - 1] + ret[i - 2]; // 현재 값은 이전 두 값의 합
        ret[i] %= MOD; // MOD로 나눈 나머지 저장
    }

    return ret; // 피보나치 수열 반환
}

// n번째 피보나치 수를 반환하는 함수
int getFibo(int n) {
    int answer = FIBONACCI_TABLE[n]; // 전역 벡터에 저장된 피보나치 수열에서 n번째 값 가져오기
    return answer; // 결과 반환
}

// 메인 함수
int main() {
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N); // 최대 n까지의 피보나치 수열 생성하여 전역 벡터에 저장

    int caseSize;
    scanf("%d", &caseSize); // 테스트 케이스 개수 입력

    // 테스트 케이스 처리
    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        int n;
        scanf("%d", &n); // n 값 입력

        int answer = getFibo(n); // n번째 피보나치 수 구하기
        printf("%d\n", answer); // 결과 출력
    }

    FIBONACCI_TABLE.clear(); // 피보나치 수열을 저장한 전역 벡터 비우기

    return 0; // 프로그램 종료
}