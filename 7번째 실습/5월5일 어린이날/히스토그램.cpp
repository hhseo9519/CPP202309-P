#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

// 히스토그램 클래스 정의
class Histogram {
public:
    int height; // 히스토그램의 높이
    int leftX;  // 히스토그램의 왼쪽 끝 인덱스
    int rightX; // 히스토그램의 오른쪽 끝 인덱스

    // 기본 생성자
    Histogram() {}

    // 인덱스와 높이를 입력받는 생성자
    Histogram(int index, int height) {
        this->leftX = index;                 // 히스토그램의 왼쪽 끝 인덱스 설정
        this->rightX = this->leftX + 1;      // 히스토그램의 오른쪽 끝 인덱스 설정
        this->height = height;               // 히스토그램의 높이 설정
    }
};

// 히스토그램으로 구성된 직사각형 영역의 최대 넓이를 계산하는 함수
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
    long long answer = 0;           // 최대 넓이를 저장하는 변수
    stack<Histogram> stk;           // 스택을 이용하여 최대 넓이 계산

    stk.push(Histogram(-1, 0));     // 초기화: 높이 0의 히스토그램을 스택에 삽입
    for (int i = 0; i < histograms.size() + 1; i++) { // 히스토그램의 수 + 1번 반복
        Histogram h;                // 현재 히스토그램
        if (i < histograms.size()) {
            h = histograms[i];      // 현재 히스토그램 설정
        }
        else {
            h = Histogram(histograms.size(), 0); // 마지막 추가된 가상 히스토그램
        }
        while (stk.size() > 1 && stk.top().height > h.height) { // 스택의 top이 현재 히스토그램보다 높으면
            Histogram lh = stk.top();   // 스택의 top 히스토그램
            stk.pop();                  // 스택에서 제거
            Histogram bh = stk.top();   // 그 다음 히스토그램 (bottom 히스토그램)

            long long width = abs(h.leftX - bh.rightX); // 너비 계산
            long long height = lh.height;              // 높이
            long long area = width * height;            // 넓이 계산

            answer = max(answer, area); // 최대 넓이 갱신
        }
        stk.push(h); // 현재 히스토그램 스택에 삽입
    }

    return answer; // 최대 넓이 반환
}

int main() {
    int caseSize;
    cin >> caseSize; // 케이스 수 입력

    vector<long long> answers; // 각 케이스의 결과를 저장하는 벡터
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { // 케이스 수만큼 반복
        int n;
        cin >> n; // 히스토그램의 수 입력

        vector<Histogram> histograms; // 히스토그램들을 저장하는 벡터
        for (int i = 0; i < n; i++) { // 히스토그램의 수만큼 반복
            int height;
            cin >> height; // 히스토그램의 높이 입력
            histograms.push_back(Histogram(i, height)); // 히스토그램 벡터에 추가
        }

        long long answer = getLargestRectangleArea(histograms); // 히스토그램 영역의 최대 넓이 계산
        answers.push_back(answer); // 결과 벡터에 추가
    }

    // 모든 케이스의 결과를 출력
    for (const auto& answer : answers) {
        cout << answer << endl;
    }

    return 0;
}