#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int findIndex(int data[], int n)
{
	int sum = 0, x = 0;// 총합을 저장하는 변수sum과 인덱스의 값을 저장 할 변수 x를 선언합니다.
	for (int i = 0; i < n; i++) {
		sum += data[i];//평균과의 거리이므로 평균을 구하기 위한 총합 sum을 구해야 하고, sum에 data배열의 값들을 누적해서 더해줍니다.
	}
	for (int i = 0; i < n; i++) {
		int dx = abs(n * data[x] - sum);//나눗셈을 사용하지 않기 위해 각 항에 n값을 곱해준 값의 절댓값을 dx에 저장합니다.
		int di = abs(n * data[i] - sum);//나눗셈을 사용하지 않기 위해 각 항에 n값을 곱해준 값의 절댓값을 di에 저장합니다.
		if (dx > di) {
			x = i; //만약 dx가 di보다 크다면 x에 i를 저장하여 거리가 더 작은 항의 인덱스를 x에 저장합니다.
		}
	}
	return x + 1;//실제 번호는 1부터 시작하기 때문에 x+1을 반환합니다.
}
int main() {
    int n; // 배열의 크기를 저장할 변수
    int* data; // 동적으로 할당된 배열을 가리키는 포인터

    scanf("%d", &n); // 배열의 크기를 입력받습니다.

    data = new int[n]; // 배열의 크기에 맞게 동적으로 메모리를 할당합니다.

    // 사용자로부터 배열의 각 요소를 입력받습니다.
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // findIndex 함수를 호출하여 최적 인덱스를 찾고, 해당 인덱스와 해당 요소를 출력합니다.
    int answer = findIndex(data, n);
    printf("%d %d\n", answer, data[answer - 1]); // 실제 인덱스는 0부터 시작하지 않으므로 1을 빼고 출력합니다.

    delete[] data; // 동적으로 할당된 메모리를 반환합니다.
    return 0; // 프로그램 종료
}
