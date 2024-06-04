#include <cstdio>
#include <iostream>

using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end)//주어진 범위에서 가장 작은 원소의 위치를 찾는 함수
{
	int index = begin;// 주어진 범위에서의 첫번째 인덱스를 저장하는 변수 begin으로 index변수를 초기화 시킵니다.

	for (int i = begin; i <= end; i++)
	{
		/* data배열에서 data[i]가 data[index]보다 작다면 index에 i를 저장합니다.
		그렇게 계속 반복해서 i가 end와 같아질때 멈추는데
		그렇게 하면 주어진 범위에서의 가장 작은 원소의 인덱스를 index변수에 저장할 수 있게 됩니다.*/
		if (data[index] > data[i])
		
		{
			index = i;
		}
	}
	return index;//위의 결과로 얻어진 주어진 범위에서의 가장 작은 원소의 위치가 저장된 index의 값을 반환합니다.
}

void selectionSort(int data[], int n)
{
	for (int i = 0; i < n; i++) {
		int minIndex = getMinIndexInRange(data, n, i, n -1);//주어진 범위에서 가장 작은 원소의 위치를 찾습니다

		//2개의 숫자가 저장되어 있는 위치를 변경한다 결과적으로 data[i]에 현재 주어진 범위에서의 가장 작은 원소가 저장됩니다.
		int num = data[minIndex];
		data[minIndex] = data[i];
		data[i] = num;
	}
}

int main() {
    int n; // 정수 n을 선언하여 입력할 숫자의 개수를 저장할 변수로 사용합니다.
    int* data; // 동적으로 할당된 정수 배열을 가리키는 포인터 변수 data를 선언합니다.

    // 사용자로부터 n의 값을 입력받습니다.
    scanf("%d", &n);

    // 길이가 n인 정수 배열을 동적으로 할당하여 data에 할당합니다.
    data = new int[n];

    // 사용자로부터 n개의 정수를 입력받아 data 배열에 저장합니다.
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // 선택 정렬(selection sort) 알고리즘을 사용하여 data 배열을 정렬합니다.
    selectionSort(data, n);

    // 정렬된 data 배열을 출력합니다.
    for (int i = 0; i < n; i++) {
        // 출력 형식을 맞추기 위해 i가 0보다 큰 경우 공백을 출력합니다.
        if (i > 0) {
            printf(" ");
        }
        // data[i]를 출력합니다.
        printf("%d", data[i]);
    }

    // 동적으로 할당된 메모리를 반환합니다.
    delete[] data;
    return 0;
}