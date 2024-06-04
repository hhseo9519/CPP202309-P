#include<iostream>
#include<queue>
using namespace std;

// 그래프의 인접 행렬을 저장할 2차원 배열 'map'을 초기화
int map[10][10] = { 0 };
// 방문한 노드를 추적할 배열 'visit'을 초기화
int visit[10] = { 0 };
// BFS 탐색에 사용할 큐를 생성
queue<int> q;
// 노드의 수와 간선의 수를 저장할 변수
int num, edge_num;

// 노드 'v'에서 BFS 탐색을 수행하는 함수
void bfs(int v) {
    // 시작 노드를 출력
    cout << v << "\n";
    // 시작 노드를 큐에 추가
    q.push(v);

    // 큐가 비어 있지 않은 동안 BFS 탐색을 계속 수행
    while (!q.empty()) {
        // 큐의 앞에 있는 노드를 가져옴
        int node = q.front();
        // 큐의 앞에 있는 노드를 제거
        q.pop();

        // 모든 가능한 노드를 반복
        for (int i = 0; i <= num; i++) {
            // 현재 노드에서 노드 'i'로의 간선이 있고, 노드 'i'가 방문되지 않았는지 확인
            if (map[node][i] == 1 && visit[i] == 0) {
                // 현재 노드를 방문으로 표시
                visit[node] = 1;
                // 연결된 노드를 출력
                cout << i << "\n";
                // 연결된 노드를 큐에 추가
                q.push(i);
            }
        }
    }
}

int main() {
    // 노드의 수와 간선의 수를 입력받음
    cin >> num >> edge_num;

    // 각 간선을 입력받아 인접 행렬을 업데이트
    for (int i = 0; i < edge_num; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        // 무방향 그래프이므로 양방향을 모두 1로 표시
        map[v1][v2] = map[v2][v1] = 1;
    }

    // 노드 1에서 BFS 탐색을 시작
    bfs(1);

    return 0;
}