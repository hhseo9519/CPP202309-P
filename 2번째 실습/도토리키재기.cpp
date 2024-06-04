#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <iostream>
using namespace std;

// 도토리의 키와 생일을 입력 받고 특정 달에 해당하는 도토리의 최대 키를 반환하는 함수
int getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxHeight = -1;//없는 경우 -1을 출력해야하기 때문에 -1로 초기화
	for (int i = n - 1; i >= 0; i--) //키가 오름차순으로 서있기 때문에 뒤에서부터 찾는것이 연산량에 있어 효율적임
	{
		if (month[i] == m)//입력 받은 현재 달의 값과 도토리의 생일 달이 같은 경우를 체크
		{
			maxHeight = height[i];//생일이 일치하는 경우에 해당 도토리의 키를 최대키로 설정
			break; //이미 원하는 도토리를 찾았으므로 break를 통해 가지치기를 할 수 있다.
		}
	}
	return maxHeight; //maxHeight를 반환


}

int main()
{
	int n, m;
	int* height; // 도토리의 키 배열 포인터
	int* month; // 도토리의 생일 달 배열 포인터

	scanf("%d", &n); // 도토리의 수 입력

	// 도토리의 키와 생일 정보를 저장할 배열 동적 할당
	height = new int[n];
	month = new int[n];

	// 각 도토리의 키를 입력받아 height배열에 저장
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &height[i]);
	}

	// 각 도토리의 생일을 입력받아 month배열에 저장
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m); // 현재 달 입력

	// 입력된 정보를 바탕으로 현재 달에 해당하는 도토리의 최대 키를 구함
	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer); // 최대 키 출력

	delete[] height; // 동적 할당된 메모리 해제
	delete[] month;
	return 0;
}