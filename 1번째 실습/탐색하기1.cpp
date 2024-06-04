#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

int findIndex(int data[], int n, int m) {
	int index = -1;//찾고자 하는 값의 인덱스를 출력하기 위한 변수 선언, 찾고자 하는 값이 배열에 없다면 -1을 반환해야 하므로 -1로 초기화합니다.
	for (int i = 0; i < n; i++)
	{
		if (data[i] == m)//찾고자 하는 값인 m과 같은 값이 존재하는 배열의 인덱스를 찾으면 index변수에 저장합니다.
		{
			index = i;
		}
	}
	return index;//index를 반환합니다.
}
int main() {
    int n, m; // 정수 n과 m을 선언하여 입력할 숫자의 개수와 찾을 값 m을 저장할 변수로 사용합니다.
    int* data; // 동적으로 할당된 정수 배열을 가리키는 포인터 변수 data를 선언합니다.

    // 사용자로부터 n과 m의 값을 입력받습니다.
    scanf("%d %d", &n, &m);

    // 길이가 n인 정수 배열을 동적으로 할당하여 data에 할당합니다.
    data = new int[n];

    // 사용자로부터 n개의 정수를 입력받아 data 배열에 저장합니다.
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // findIndex 함수를 호출하여 배열 data에서 값 m의 인덱스를 찾습니다.
    int answer = findIndex(data, n, m);

    // 찾은 인덱스를 출력합니다.
    printf("%d\n", answer);

    // 동적으로 할당된 메모리를 반환합니다.
    delete[] data;
    return 0;
}