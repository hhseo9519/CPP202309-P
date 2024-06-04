#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

// 버블 정렬 함수
void bubbleSort(int data[], int n) {
    for (int i = 0; i < n; i++) { // 배열의 모든 요소에 대해 반복
        int negativecount = 0; // 정렬이 완료되었는지 확인하기 위한 변수 초기화
        for (int j = 0; j < n - 1 - i; j++) { // 배열의 요소를 비교하며 정렬
            if (data[j] > data[j + 1]) { // 현재 요소와 다음 요소를 비교하여 정렬이 필요한 경우
                int temp = data[j]; // 두 요소를 교환
                data[j] = data[j + 1];
                data[j + 1] = temp;
                negativecount++; // 정렬이 이루어졌음을 표시
            }
        }
        if (negativecount == 0) { // 정렬이 더 이상 필요하지 않을 경우
            break; // 반복 종료
        }
    }
}

int main() {
    int n; // 입력 받을 데이터의 개수
    int* data; // 입력 받을 데이터를 저장할 배열 포인터

    scanf("%d", &n); // 데이터의 개수 입력 받기
    data = new int[n]; // 배열 동적 할당

    // 데이터 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n); // 데이터 정렬

    // 정렬된 데이터 출력
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // 첫 번째 데이터를 제외하고 공백 출력
        }
        printf("%d", data[i]); // 데이터 출력
    }

    delete[] data; // 동적 할당된 배열 메모리 해제
    return 0;
}