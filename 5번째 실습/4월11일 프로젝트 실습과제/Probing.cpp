#include <cstdio>
#include <vector>
#include <unordered_map> // 해시 맵을 사용하기 위한 헤더 파일

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class TicketTable {
public:
    vector<bool> used; // 사용 여부를 저장하는 벡터
    int length; // 티켓 테이블의 길이를 저장할 변수 선언

    // 생성자: 티켓 테이블 초기화
    TicketTable(int length) {
        this->length = length;
        this->used.assign(length, false); // 모든 티켓을 미사용 상태로 초기화
    }

    // 사용자 ID를 기반으로 빈 티켓 인덱스를 찾는 함수
    int findEmptyIndexByUserId(int userId) {
        int index = userId % length; // 사용자 ID를 티켓 인덱스로 변환
        while (this->isEmpty(index) == true) {
            index = (index + 1) % length; // 충돌 발생 시 선형 탐사를 통해 다음 인덱스로 이동
        }
        return index;
    }

    // 특정 인덱스의 티켓이 사용 가능한지 확인하는 함수
    bool isEmpty(int ticketIndex) {
        return this->used[ticketIndex];
    }

    // 특정 인덱스의 티켓 사용 여부를 설정하는 함수
    void setUsed(int index, bool status) {
        this->used[index] = status;
    }
};

// 사용자 ID를 기반으로 티켓을 할당하는 함수
vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
    vector<int> tickets;
    TicketTable table = TicketTable(n); // 티켓 테이블 생성

    for (int i = 0; i < m; i++) {
        int userId = ids[i];
        int ticketIndex = table.findEmptyIndexByUserId(userId); // 사용자 ID를 기반으로 빈 티켓 인덱스 찾기
        tickets.push_back(ticketIndex); // 할당된 티켓 인덱스 저장
        table.setUsed(ticketIndex, true); // 해당 티켓을 사용으로 표시
    }
    return tickets; // 할당된 티켓 인덱스 반환
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m); // 티켓 테이블의 길이와 사용자 수 입력

    vector<int> ids(m); // 사용자 ID를 저장하는 벡터

    for (int i = 0; i < m; i++) {
        scanf("%d", &ids[i]); // 사용자 ID 입력
    }

    // 티켓 할당 및 출력
    vector<int> tickets = getTicketNumbers(n, m, ids);
    for (int i = 0; i < m; ++i) {
        printf("%d\n", tickets[i]); // 각 사용자의 티켓 출력
    }
}