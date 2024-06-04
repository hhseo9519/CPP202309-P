#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void solve(int data[], int n, int p, int q)
{
	int count = 0;// 총 탈 수 있는 사람 수를 세기위한 변수 선언
	int weight_sum = 0;// 탈 수 있는 사람들의 몸무게의 합을 저장하기 위한 변수 선언
	for (int i = 0; i < n; i++)// main 함수에서 입력받은 데이터들을 이용하여 변수 count,weight_sum을 업데이트 한다
	{
		if (data[i] <= p)// 기준이 되는 몸무게 p보다 작을 경우 count를 1씩 증가, weight_sum에 해당 인덱스 값을 더하여 누적해 나감.
		{
			count++;
			weight_sum += data[i];
		}
	}
	printf("%d %d \n", count, weight_sum); //출력 형식에 맞게 count와 weight_sum을 출력
	if (weight_sum <= q)//weight_sum이 q보다 작은경우 모두 함께 탑승 가능하므로 YES를 출력, 아닌경우 NO를 출력 
	{
		printf("YES \n");
	}
	else {
		printf("NO \n");
	}
}
int main() {
	int n, p, q; // n: 사람의 수, p: 기준 몸무게, q: 허용되는 최대 총 몸무게
	int* data; // 사람들의 몸무게를 저장할 동적 배열의 포인터

	// 사람의 수, 기준 몸무게, 허용되는 최대 총 몸무게를 입력받습니다.
	scanf("%d %d %d", &n, &p, &q);

	data = new int[n]; // n 크기의 동적 배열 할당합니다.

	// 각 사람들의 몸무게를 입력받아 배열에 저장합니다.
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	// solve 함수를 호출하여 문제를 해결합니다.
	solve(data, n, p, q);

	delete[] data; // 동적으로 할당된 메모리를 반환합니다.
	return 0; // 프로그램 종료
}