#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include<climits> // INT_MAX 상수를 사용하기 위해 포함
#include<cmath> // sqrt 함수를 사용하기 위해 포함
using namespace std;

class point2D {
private:
    int x; // x 좌표
    int y; // y 좌표
public:
    point2D(int x = 0, int y = 0) { // 생성자, 기본값은 (0, 0)
        this->x = x;
        this->y = y;
    }
    int getSquareDistanceTo(const point2D& target) const { // 두 점 사이의 거리의 제곱을 반환하는 메서드
        int dx = this->x - target.x; // x 좌표 차이
        int dy = this->y - target.y; // y 좌표 차이
        return dx * dx + dy * dy; // 거리의 제곱 반환
    }
    double getDistanceTo(const point2D& target) const { // 두 점 사이의 거리를 반환하는 메서드
        double sqd = (double)getSquareDistanceTo(target); // 거리의 제곱
        return sqrt(sqd); // 제곱근 반환
    }

};

int main() {
    int n; // 점의 개수
    point2D* points; // 점 객체 배열 포인터

    scanf("%d", &n); // 점의 개수 입력 받기
    points = new point2D[n]; // 점 객체 배열 동적 할당

    for (int i = 0; i < n; i++) { // 각 점의 좌표 입력 받기
        int x, y; // x, y 좌표
        scanf("%d %d", &x, &y); // x, y 좌표 입력 받기

        points[i] = point2D(x, y); // 점 객체 배열에 좌표 저장
    }

    int min_sqd = INT_MAX; // 최소 거리의 제곱, 초기값은 정수형의 최대값
    int min_cnt = 0; // 최소 거리의 개수, 초기값은 0

    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { // 현재 점부터 마지막까지 체크
            int sqd = points[i].getSquareDistanceTo(points[j]); // 두 점 사이의 거리의 제곱 계산
            if (sqd < min_sqd) { // 현재 거리의 제곱이 최소 거리의 제곱보다 작으면 최소 거리 재정의
                min_sqd = sqd; // 최소 거리 재정의
                min_cnt = 1; // 최소 거리 개수 초기화
            }
            else if (sqd == min_sqd) { // 현재 거리의 제곱이 최소 거리의 제곱과 같으면 최소거리의 개수를 증가시킴
                min_cnt++; // 최소 거리 개수 증가
            }
        }
    }

    double distance = sqrt(min_sqd); // 최소 거리의 제곱근을 구함
    printf("%.1f\n", distance); // 소수점 첫째 자리까지 출력
    printf("%d\n", min_cnt); // 최소 거리의 개수 출력

    delete[] points; // 동적 할당된 메모리 해제
    return 0;
}