#define _CRT_SECURE_NO_WARNINGS // 컴파일러에서 보안 경고를 무시하기 위한 선언

#include <cstdio> // C 표준 입출력 헤더 파일
#include <iostream> // C++ 표준 입출력 헤더 파일

using namespace std; // std 네임스페이스를 사용

// 1부터 i까지의 합을 반환하는 함수
int getRangeSumFromOne(int i) {
    int answer = 0;
    for (int j = 0; j <= i; j++) {
        answer += j;
    }
    return answer;
}

// 0부터 N까지의 각각의 1부터 i까지의 합을 구한 뒤 모두 더한 값을 반환하는 함수
long long getAnswer(int N) {
    long long answer = 0; // 답을 저장할 변수 선언 및 초기화
    for (int i = 0; i <= N; i++) { // 0부터 N까지 반복
        int rangesum = getRangeSumFromOne(i); // 1부터 i까지의 합 계산
        answer += rangesum; // 계산된 합을 전체 답에 더함
    }
    return answer; // 전체 답 반환
}

int main() {
    int n;

    scanf("%d", &n); // 사용자로부터 정수 입력 받음

    long long answer = getAnswer(n); // getAnswer 함수 호출하여 답 계산

    printf("%lld\n", answer); // 계산된 답을 출력

    return 0; 
}