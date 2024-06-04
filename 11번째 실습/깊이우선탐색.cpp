#include<iostream>

using namespace std;

// 그래프의 인접 행렬을 저장할 2차원 배열 'maps'
int maps[10][10];
// 방문한 노드를 추적할 배열 'visited'
int visited[10] = { 0 };
// 노드의 수를 저장할 변수 'num'
int num;

// 인접 행렬과 방문 배열을 초기화하는 함수
void init() {
    // 인접 행렬의 모든 값을 0으로 초기화
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maps[i][j] = 0;
        }
    }
}

// 깊이 우선 탐색(DFS)을 수행하는 함수
void dfs(int v) {
    // 현재 노드를 출력
    cout << v << endl;
    // 현재 노드를 방문으로 표시
    visited[v] = 0;

    // 모든 가능한 노드를 반복
    for (int i = 0; i <= num; i++) {
        // 현재 노드와 노드 'i' 사이에 간선이 있고, 노드 'i'가 방문되지 않았는지 확인
        if (maps[v][i] && visited[i]) {
            // 노드 'i'에 대해 DFS를 재귀적으로 호출
            dfs(i);
        }
    }
}

int main(void) {
    int v1, v2;
    // 인접 행렬과 방문 배열을 초기화
    init();
    // 노드의 수를 입력받음
    cin >> num;

    // 각 간선을 입력받아 인접 행렬을 업데이트
    for (int i = 0; i < num; i++) {
        cin >> v1 >> v2;
        // 무방향 그래프이므로 양방향을 모두 1로 표시
        maps[v1][v2] = maps[v2][v1] = 1;
        // 방문 배열을 1로 설정하여 노드가 존재함을 표시
        visited[v1] = visited[v2] = 1;
    }

    // 노드 1에서 DFS 탐색을 시작
    dfs(1);

    return 0;
}