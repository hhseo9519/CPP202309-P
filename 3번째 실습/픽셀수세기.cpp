#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// 원 안에 포함되는지 여부를 판단하는 함수
bool isInseide(long long x, long long y, long long R) {
    long long sqd = x * x + y * y; // x, y 좌표의 제곱 거리 계산
    if (sqd < R * R) { // 제곱 거리가 반지름의 제곱보다 작으면 원 안에 포함됨
        return true;
    }
    return false;
}

// 반지름에 따른 면적 계산 함수
long long testcase(long long R) {
    long long sum = 0; // 총 픽셀 수를 저장할 변수
    long long y = R; // 초기 y 좌표를 반지름으로 설정
    // 1사분면 내에서 x 좌표를 증가시키면서 탐색
    for (long long x = 0; x <= R; x++) {
        long long height = 0; // 현재 x 좌표에서의 높이
        // y 좌표를 내려가면서 원 내부에 있는지 확인
        for (; y >= 0; y--) {
            if (isInseide(x, y, R)) { // 원 내부에 있는 경우
                height = (y + 1); // 현재 높이 설정
                break; // 내부에 있으면 더 내려갈 필요 없음
            }
        }
        sum += height; // 현재 x 좌표에서의 높이를 총 픽셀 수에 추가
    }
    return sum * 4; // 1사분면에서 계산한 면적을 4배하여 전체 면적으로 확장
}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // 케이스 수 입력 받기
    vector<long long> radiuses(caseSize); // 반지름을 저장할 벡터 생성

    // 반지름 입력 받기
    for (int i = 0; i < caseSize; i++) {
        scanf("%lld", &radiuses[i]);
    }

    // 결과 출력
    for (int i = 0; i < caseSize; i++) {
        long long area = testcase(radiuses[i]); // 해당 반지름에 대한 면적 계산
        printf("#%d\n%lld\n", i + 1, area); // 결과 출력
    }

    return 0;
}