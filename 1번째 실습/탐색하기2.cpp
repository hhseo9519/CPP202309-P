#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
void printIndexes(string school[], int n)
{
	int first = -1;
	int last = -1;//첫번째와 마지막 아주대학교 학생의 인덱스를 저장할 first와 last변수를 선언
	for (int i = 0; i < n; i++)// AJOU대학교 학생들의 인덱스를 찾기 위한 반복문 실행
	{
		if (school[i]== "AJOU")// 배열 school의 해당 인덱스에 저장되어있는 문자열이 AJOU와 같다면 아래 문장 실행
		{
			if (first == -1)//위의 if문의 조건을 만족 하면서 first가 -1일때 first에 i+1을 저장
				first = i + 1;
			last = i + 1;//배열 school의 해당 인덱스에 저장되어있는 문자열이 AJOU와 같지만 first가 -1이 아닐때 실행
		}
	}
	printf("%d %d\n", first, last);// 출력 형식에 맞게 first와 last를 출력
}
int main() {
    int n; // 학생 수를 저장할 변수
    char buff[11]; // 문자열을 일시적으로 저장할 배열 (문자열은 최대 10글자 + 널 문자 '\0'을 고려해 크기를 11로 잡음)
    string* school; // 학교명을 저장할 동적 문자열 배열의 포인터

    scanf("%d", &n); // 사용자로부터 학생 수를 입력받음

    school = new string[n]; // 학생 수에 따라 동적으로 문자열 배열 할당

    // 학생의 학교명을 입력받아 school 배열에 저장
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buff); // 문자열을 입력받아 buff 배열에 저장
        school[i] = buff; // buff에 저장된 문자열을 school 배열에 복사
    }

    // 함수를 호출하여 아주대학교 학생들의 인덱스를 출력
    printIndexes(school, n);

    delete[] school; // 동적으로 할당된 메모리 반환
    return 0; // 프로그램 종료
}