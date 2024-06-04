#define _CRT_SECURE_NO_WARNINGS // Visual Studio에서 scanf 사용 관련 경고를 억제하기 위한 전처리 지시문

#include <cstdio> // C 표준 입출력 라이브러리
#include <vector> // C++ 표준 라이브러리의 vector 포함

using namespace std; // 표준 라이브러리 함수와 객체를 std::를 붙이지 않고 사용하기 위한 using 지시문

const int MAX_SEAT_NUMBER = 1000; // 가능한 최대 좌석 번호
const int MAX_COLOR_NUMBER = 100; // 가능한 최대 색상 번호

// 그림 클래스 선언
class Painting {
public:
    int left; // 그림의 왼쪽 좌석 번호
    int right; // 그림의 오른쪽 좌석 번호
    int color; // 그림의 색상

    // 기본 생성자
    Painting() {}

    // 초기화 생성자
    Painting(int left, int right, int color) {
        this->left = left;
        this->right = right;
        this->color = color;
    }
};

// 데이터의 빈도를 저장하는 함수
void fillFrequencyTable(int data[], int n, int table[]) {
    // 테이블 배열 초기화
    for (int i = 0; i < MAX_COLOR_NUMBER; i++) {
        table[i] = 0;
    }

    // 데이터 배열을 반복하며 빈도 테이블 채우기
    for (int i = 0; i < n; i++) {
        int color = data[i];
        table[color] += 1;
    }
}

// 문제 해결을 위한 함수
void solve(int n, int m, const Painting* paintings) {
    int* seats = new int[n]; // 좌석 배열 동적 할당 및 초기화

    // 좌석 배열 초기화
    for (int i = 0; i < n; i++) {
        seats[i] = 0;
    }

    // 그림 배열을 반복하며 좌석 배열에 색상 할당
    for (int i = 0; i < m; i++) {
        const Painting& p = paintings[i];

        // 그림의 왼쪽부터 오른쪽까지 좌석에 색상 할당
        for (int j = p.left; j <= p.right; j++) {
            seats[j] = p.color;
        }
    }

    int* table = new int[MAX_COLOR_NUMBER]; // 빈도 테이블을 저장할 배열 동적 할당
    fillFrequencyTable(seats, n, table); // 좌석 배열로부터 빈도 테이블 채우기

    int minColor = seats[0]; // 최소 빈도를 가진 색상 초기화
    int maxColor = seats[0]; // 최대 빈도를 가진 색상 초기화

    // 빈도 테이블을 순회하며 최소 빈도와 최대 빈도를 가진 색상 찾기
    for (int color = 0; color < MAX_COLOR_NUMBER; color += 1) {
        if (table[color] == 0) {
            continue; // 해당 색상이 사용되지 않은 경우 다음 색상으로 넘어감
        }

        // 현재 색상이 최소 빈도를 가진 색상보다 더 적은 빈도를 가지는 경우 최소 빈도를 가진 색상 변경
        if (table[minColor] > table[color]) {
            minColor = color;
        }

        // 현재 색상이 최대 빈도를 가진 색상보다 더 많은 빈도를 가지는 경우 최대 빈도를 가진 색상 변경
        if (table[maxColor] < table[color]) {
            maxColor = color;
        }
    }

    // 최대 빈도를 가진 색상과 최소 빈도를 가진 색상 출력
    printf("%d\n", maxColor);
    printf("%d\n", minColor);

    delete[] table; // 동적 할당한 빈도 테이블 메모리 반환
}

// 메인 함수
int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 좌석 수와 그림 수 입력받음

    Painting* paintings = new Painting[n]; // 그림 배열 동적 할당

    // 그림 정보 입력
    for (int i = 0; i < m; i++) {
        scanf("%d", &paintings[i].left); // 그림의 왼쪽 좌석 번호 입력
        scanf("%d", &paintings[i].right); // 그림의 오른쪽 좌석 번호 입력
        scanf("%d", &paintings[i].color); // 그림의 색상 입력

        paintings[i].left -= 1; // 좌석 번호는 0부터 시작하므로 1을 빼줌
        paintings[i].right -= 1; // 좌석 번호는 0부터 시작하므로 1을 빼줌
    }

    solve(n, m, paintings); // 문제 해결 함수 호출

    return 0; // 프로그램 정상 종료
}