#define _CRT_SECURE_NO_WARNINGS // Visual Studio에서 특정 함수의 사용으로 발생하는 경고를 무시하기 위한 전처리기 지시문

#include <cstdio> // 파일 입출력 및 포맷된 입출력을 위한 표준 라이브러리 헤더 파일

using namespace std;

const int MAX_TABLE_LENGTH = 10000; // 테이블 배열의 최대 길이를 정의하는 상수

// 주어진 데이터 배열에서 숫자의 빈도를 계산하여 빈도 테이블에 저장하는 함수
void fillFrequencyTable(int data[], int n, int table[]) {
    int frequent_number = 0; // 빈도가 가장 높은 숫자를 저장하는 변수
    for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
        table[i] = 0; // 테이블 초기화
    }
    for (int i = 0; i < n; i++) {
        frequent_number = data[i]; // 데이터 배열의 값을 가져와서 frequent_number에 저장
        table[frequent_number] += 1; // 빈도 테이블에서 해당 숫자의 빈도 증가
    }
}

// 가장 빈번하게 나타나는 숫자를 찾는 함수
int getFrequentNumber(int data[], int n) {
    int frequent_number = 0; // 빈도가 가장 높은 숫자를 저장하는 변수

    int table[MAX_TABLE_LENGTH]; // 빈도 테이블 배열 선언
    fillFrequencyTable(data, n, table); // fillFrequencyTable 함수 호출하여 빈도 테이블 생성

    // 빈도 테이블을 순회하면서 가장 빈번하게 나타나는 숫자를 찾음
    for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
        if (table[i] > table[frequent_number]) {
            frequent_number = i; // 빈도가 더 높은 숫자를 frequent_number에 저장
        }
    }
    return frequent_number; // 가장 빈번하게 나타나는 숫자 반환
}

int main() {
    int n; // 데이터 배열의 길이를 저장할 변수

    scanf("%d", &n); // 사용자로부터 데이터 배열의 길이 입력받음
    int* data = new int[n]; // 길이가 n인 정수 배열 동적 할당

    // 사용자로부터 데이터 입력받아 배열에 저장
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int answer = getFrequentNumber(data, n); // 가장 빈번하게 나타나는 숫자를 찾음

    printf("%04d", answer); // 결과 출력

    delete[] data; // 동적으로 할당된 메모리 해제

    return 0;
}