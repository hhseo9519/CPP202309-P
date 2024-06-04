#define _CRT_SECURE_NO_WARNINGS // Visual Studio에서 scanf 사용 관련 경고를 억제하기 위한 전처리 지시문

#include<cstdio> // scanf 및 printf와 같은 C 표준 입출력 라이브러리를 포함
#include<vector> // C++ 표준 템플릿 라이브러리(STL)의 vector 컨테이너 포함
#include<algorithm> // C++ STL의 알고리즘 함수들을 포함

using namespace std; // 표준 라이브러리 함수와 객체를 std::를 붙이지 않고 사용하기 위한 using 지시문

const int MAX_SERIAL_NUMBER = 100000; // 가능한 최대 시리얼 번호를 나타내는 상수

// 데이터의 요소가 발생하는 빈도를 기록하는 함수
void fillFrequencyTable(const vector<int>& data, int n, vector<int>& table) {
    table.clear(); // 테이블 벡터를 지움
    table.resize(MAX_SERIAL_NUMBER + 1, 0); // 테이블 벡터 크기를 조정하고 모든 요소를 0으로 초기화

    // 데이터 벡터를 반복
    for (int i = 0; i < n; ++i) {
        int serial = data[i]; // 데이터의 인덱스 i에 있는 시리얼 번호를 가져옴
        table[serial] += 1; // 테이블에 있는 시리얼 번호의 카운트를 증가
    }
}

// 데이터에서 고유한 요소를 찾는 함수
vector<int> getUniqueElements(const vector<int>& data, int n) {
    vector<int> ret; // 고유한 요소를 저장하기 위한 벡터

    vector<int> table; // 요소의 빈도를 저장하기 위한 벡터
    fillFrequencyTable(data, n, table); // 빈도 테이블 채우기

    // 가능한 시리얼 번호를 반복
    for (int number = 1; number <= MAX_SERIAL_NUMBER; number = +1) {
        // 번호의 빈도가 1인 경우, 고유함
        if (table[number] == 1) {
            ret.push_back(number); // 고유한 번호를 반환 벡터에 추가
        }
    }
    return ret; // 고유한 요소를 포함하는 벡터 반환
}

int main() {
    int n;
    scanf("%d", &n); // 데이터 배열의 크기를 읽음

    vector<int> data = vector<int>(n); // 데이터를 저장하기 위한 크기 n의 벡터 생성

    // 데이터 배열 요소를 읽음
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]); // 각 요소를 데이터 벡터에 읽어들임
    }

    const vector<int> answer = getUniqueElements(data, n); // 데이터에서 고유한 요소 찾기

    // 고유한 요소를 출력
    for (int i = 0; i < answer.size(); ++i) {
        if (i > 0) {
            printf(" "); // 요소 사이에 공백 출력
        }
        printf("%d", answer[i]); // 현재 요소 출력
    }
    return 0; // 프로그램이 성공적으로 완료되었음을 나타냄
}