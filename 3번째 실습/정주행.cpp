#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

// 등차수열인지 여부를 판별하는 함수
bool isConsecutive(int data[], int n) {
    int max_data = data[0]; // 최대값 초기화
    int min_data = data[0]; // 최소값 초기화

    // 최대값과 최소값 찾기
    for (int i = 0; i < n; i++) {
        if (max_data < data[i]) {
            max_data = data[i]; // 최대값 갱신
        }
        if (min_data > data[i]) {
            min_data = data[i]; // 최소값 갱신
        }
    }

    // 등차수열 여부 판별
    if (max_data - min_data == n - 1) { // 최대값과 최소값 차이가 n-1이면 등차수열
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;//입력받을 데이터의 개수를 저장할 변수 선언
    int* data;

    scanf("%d", &n); // 데이터 개수 입력 받기
    data = new int[n]; // 데이터 배열 동적 할당

    // 데이터 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // 등차수열 여부 판별
    bool result = isConsecutive(data, n);

    // 결과 출력
    if (result) {
        printf("YES"); // 등차수열이면 YES 출력
    }
    else {
        printf("NO"); // 등차수열이 아니면 NO 출력
    }

    delete[] data; // 동적 할당된 배열 메모리 해제
    return 0;
}