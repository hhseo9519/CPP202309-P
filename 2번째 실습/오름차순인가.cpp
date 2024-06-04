#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;

// 배열이 오름차순으로 정렬되어 있는지 확인하는 함수
bool isOrdered(int data[], int n)
{
	int count = 0; // 인접한 두 요소가 오름차순으로 배열되어있는지 확인할 때 사용할 변수 선언

	// for문을 통해 인접한 두 요소를 비교
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] > data[i + 1]) // 현재 요소가 다음 요소보다 큰 경우
		{
			count++; // count 변수 1증가
			break; // 오름차순이 아니라면 더이상 확인 할 필요 없이 break로 반복문 종료
		}
	}

	if (count > 0) // count가 0보다 큰, 즉 오름차순이 아닌경우
	{
		return false; // 오름차순이 아님을 반환
	}
	else // 나머지 경우, 오름차순인 경우
	{
		return true; // 오름차순임을 반환
	}
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n); // 배열의 크기 입력

	data = new int[n]; // 배열 동적 할당

	// 배열 요소 입력
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	// isOrdered 함수를 통해 배열이 오름차순으로 정렬되어 있는지 확인
	bool result = isOrdered(data, n);

	// 결과 출력
	if (result) // 오름차순인 경우 YES출력
	{
		printf("YES");
	}
	else // 오름차순이 아닌 경우 NO출력
	{
		printf("NO");
	}

	delete[] data; // 동적 할당된 배열 메모리 해제
	return 0;
}