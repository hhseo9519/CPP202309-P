#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 두 사각형이 교차하는 영역의 넓이를 계산하는 함수
int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)
{
    int l, r, t, b;
    // 각각의 사각형에서 왼쪽, 오른쪽, 위, 아래의 좌표 중 최대값을 찾음
    l = max(la, lb);
    r = min(ra, rb);
    t = min(ta, tb); // 높이가 음수가 될 수 있으므로 min 값을 사용
    b = max(ba, bb);

    // 만약 두 사각형이 겹치는 영역이 존재한다면
    if (l <= r && b <= t) {
        // 겹치는 영역의 넓이를 계산하여 반환
        return (r - l) * (t - b);
    }
    // 겹치는 영역이 없는 경우 0을 반환
    return 0;
}

// 테스트 케이스를 수행하는 함수
void test_case()
{
    int ax, ay, bx, by;
    int px, py, qx, qy;
    // 입력 받기
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    int la, ra, ba, ta; // 첫 번째 사각형의 왼쪽, 오른쪽, 아래, 위 좌표
    la = min(ax, bx);
    ra = max(ax, bx); // 두 좌표 중 작은 값이 왼쪽, 큰 값이 오른쪽
    ba = min(ay, by);
    ta = max(ay, by); // 두 좌표 중 작은 값이 아래, 큰 값이 위

    int lb, rb, bb, tb; // 두 번째 사각형의 왼쪽, 오른쪽, 아래, 위 좌표
    lb = min(px, qx);
    rb = max(px, qx); // 두 좌표 중 작은 값이 왼쪽, 큰 값이 오른쪽
    bb = min(py, qy);
    tb = max(py, qy); // 두 좌표 중 작은 값이 아래, 큰 값이 위

    // 교차하는 영역의 넓이 계산
    int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

    // 결과 출력
    printf("%d\n", answer);
}

int main() {
    int t;
    // 테스트 케이스 개수 입력 받기
    scanf("%d", &t);

    // 각 테스트 케이스에 대해 test_case 함수 호출
    for (int i = 0; i < t; i++) {
        test_case();
    }
    return 0; // 프로그램 종료
}