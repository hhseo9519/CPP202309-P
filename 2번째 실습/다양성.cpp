#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;

// 배열에서 서로 다른 원소의 개수를 세는 함수
int getElementTypeCount(int data[], int n)
{
	int countType = 0; // 서로 다른 원소의 개수를 저장하는 변수

	for (int i = 1; i < n; i++) // for문을 통해 배열의 인덱스 끼리의 비교를 반복
	{
		if (data[i - 1] != data[i]) // 원소들이 오름차순으로 되어있기 때문에 현재원소와 이전원소를 비교하여 다른경우를 체크하면 서로다른 원소의 개수를 알아내는것이 가능하다.
		{
			countType++; // 서로 다른 원소의 개수 증가
		}
	}

	return countType; // 서로 다른 원소의 개수 반환
}

int main()
{
	int n;
	int* data; // 고유번호 배열을 저장할 포인터 변수

	scanf("%d", &n); // 배열의 크기 입력

	data = new int[n]; // 배열 동적 할당

	// 배열의 원소 입력받아 data배열에 저장
	for (int i = 0; i < n; i++)
	{
		scanf("%d\n", &data[i]);
	}

	// 서로 다른 원소의 개수를 구함
	int answer = getElementTypeCount(data, n);

	printf("%d\n", answer); // 결과 출력

	delete[] data; // 동적 할당된 배열 메모리 해제
	return 0;
}