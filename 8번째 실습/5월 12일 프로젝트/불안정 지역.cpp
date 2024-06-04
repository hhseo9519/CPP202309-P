#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// 도시 클래스 정의
class City {
public:
    int index; // 도시의 인덱스
    int income; // 도시의 수입

    // 생성자
    City(int index, int income) {
        this->index = index; // 인덱스 초기화
        this->income = income; // 수입 초기화
    }

    // 수입을 기준으로 오름차순 비교 연산자 오버로딩
    bool operator<(const City& o)const {
        return this->income < o.income;
    }

    // 수입을 기준으로 내림차순 비교 연산자 오버로딩
    bool operator>(const City& o) const {
        return this->income > o.income;
    }
};

// 최대 범위 차이를 구하는 함수
int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
    int answer = 0;

    // 최소 힙과 최대 힙 정의
    priority_queue<City, vector<City>, greater<City>> rangeMinimum;
    priority_queue<City> rangeMaximum;

    // 초기 k-1개 도시를 각각의 힙에 넣음
    for (int i = 0; i < k - 1; i++) {
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]);
    }

    // 슬라이딩 윈도우 기법을 사용하여 최대 범위 차이 계산
    for (int i = k - 1; i < n; i++) {
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]);

        // 범위를 벗어난 도시를 힙에서 제거
        while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop();
        while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();

        // 현재 최대 범위 차이 갱신
        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
    }
    return answer;
}

// 각 테스트 케이스 처리하는 함수
void process(int caseIndex) {
    int n, k;
    cin >> n >> k;
    vector<City> cities;

    // 도시 정보 입력
    for (int i = 0; i < n; i += 1) {
        int income;
        cin >> income;
        cities.push_back(City(i, income)); // 도시 객체 생성하여 벡터에 추가
    }

    // 최대 범위 차이 계산
    int answer = getMaximumRangeDifference(n, k, cities);

    // 결과 출력
    cout << answer << endl;
}

// 메인 함수
int main() {
    int caseSize;
    cin >> caseSize;

    // 각 테스트 케이스에 대해 처리
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
    return 0;
}