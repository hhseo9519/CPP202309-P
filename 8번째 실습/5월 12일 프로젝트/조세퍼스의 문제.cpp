#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �÷��̾� Ŭ���� ����
class Player {
public:
    int index;

    // ������
    Player(int index) {
        this->index = index;
    }
};

// �÷��̾� ��ϰ� ���ŵǴ� �÷��̾ ����ϴ� �Լ�
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players) {
    vector<Player> deadPlayers;

    queue<Player> que;

    // �ʱ� �÷��̾� ť ����
    for (int i = 0; i < n; i += 1) {
        que.push(players[i]);
    }

    // �÷��̾� ���� �ùķ��̼�
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
    // �׽�Ʈ ���̽� �� �Է�
    int caseSize;
    cin >> caseSize;

    // �� �׽�Ʈ ���̽��� �Է��� ������ ����
    vector<vector<pair<int, int>>> inputs(caseSize);

    // �� �׽�Ʈ ���̽��� �Է��� ����
    for (int i = 0; i < caseSize; ++i) {
        int n, m;
        cin >> n >> m;
        inputs[i].push_back({ n, m }); // �Է� ����
    }

    // �� �׽�Ʈ ���̽��� ���� ó�� �� ��� ���
    for (int i = 0; i < caseSize; ++i) {
        vector<pair<int, int>> caseInputs = inputs[i];
        vector<Player> players;
        for (int j = 0; j < caseInputs.size(); ++j) {
            int n = caseInputs[j].first;
            int m = caseInputs[j].second;

            // �÷��̾� ����
            for (int k = 0; k < n; k++) {
                players.push_back(Player(k + 1));
            }

            // ���ŵ� �÷��̾� ���
            vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

            // ��� ���
            for (int k = 0; k < n; k++) {
                if (k > 0) {
                    cout << " ";
                }
                Player p = deadPlayers[k];
                cout << p.index;
            }
            cout << endl;
            players.clear(); // ���� �׽�Ʈ ���̽��� ���� �÷��̾� ��� �ʱ�ȭ
        }
    }

    return 0;
}