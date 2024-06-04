#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 플레이어 클래스 정의
class Player {
public:
    int index;

    // 생성자
    Player(int index) {
        this->index = index;
    }
};

// 플레이어 목록과 제거되는 플레이어를 계산하는 함수
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players) {
    vector<Player> deadPlayers;

    queue<Player> que;

    // 초기 플레이어 큐 설정
    for (int i = 0; i < n; i += 1) {
        que.push(players[i]);
    }

    // 플레이어 제거 시뮬레이션
    while (!que.empty()) {
        for (int i = 0; i < m - 1; i++) {
            Player p = que.front();
            que.pop();
            que.push(p);
        }
        deadPlayers.push_back(que.front());
        que.pop();
    }
    return deadPlayers;
}

int main() {
    // 테스트 케이스 수 입력
    int caseSize;
    cin >> caseSize;

    // 각 테스트 케이스의 입력을 저장할 벡터
    vector<vector<pair<int, int>>> inputs(caseSize);

    // 각 테스트 케이스의 입력을 받음
    for (int i = 0; i < caseSize; ++i) {
        int n, m;
        cin >> n >> m;
        inputs[i].push_back({ n, m }); // 입력 저장
    }

    // 각 테스트 케이스에 대해 처리 후 결과 출력
    for (int i = 0; i < caseSize; ++i) {
        vector<pair<int, int>> caseInputs = inputs[i];
        vector<Player> players;
        for (int j = 0; j < caseInputs.size(); ++j) {
            int n = caseInputs[j].first;
            int m = caseInputs[j].second;

            // 플레이어 생성
            for (int k = 0; k < n; k++) {
                players.push_back(Player(k + 1));
            }

            // 제거된 플레이어 계산
            vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

            // 결과 출력
            for (int k = 0; k < n; k++) {
                if (k > 0) {
                    cout << " ";
                }
                Player p = deadPlayers[k];
                cout << p.index;
            }
            cout << endl;
            players.clear(); // 다음 테스트 케이스를 위해 플레이어 목록 초기화
        }
    }

    return 0;
}