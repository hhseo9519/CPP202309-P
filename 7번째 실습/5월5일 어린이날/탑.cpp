#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Tower 클래스는 각 타워를 나타냅니다.
class Tower {
public:
    int index;              // 타워의 인덱스
    int height;             // 타워의 높이
    int targetTowerIndex;   // 대상 타워의 인덱스

    // 생성자는 타워 객체를 인덱스와 높이로 초기화합니다.
    Tower(int index, int height) {
        this->index = index;
        this->height = height;
        this->targetTowerIndex = 0; // 대상 타워의 인덱스를 0으로 초기화합니다.
    }

    // 대상 타워의 인덱스를 설정하는 메서드입니다.
    void setTargetTowerIndex(int targetTowerIndex) {
        this->targetTowerIndex = targetTowerIndex;
    }

    // 대상 타워의 인덱스를 반환하는 메서드입니다.
    int getTargetTowerIndex() {
        return this->targetTowerIndex;
    }
};

// 각 타워의 대상 타워를 찾는 함수입니다.
void findTargetTowers(vector<Tower>& towers) {
    stack<Tower> stk; // 타워를 저장하는 스택입니다.

    // 각 타워를 반복합니다.
    for (int i = 0; i < towers.size(); i++) {
        Tower& t = towers[i]; // 현재 타워에 대한 참조입니다.

        int targetTowerIndex = 0; // 대상 타워의 인덱스 (0으로 초기화)

        // 스택이 비어있지 않고, 스택의 맨 위 타워가 현재 타워보다 작을 때까지 타워를 팝합니다.
        while (stk.empty() == false && stk.top().height < t.height) {
            stk.pop(); // 스택에서 더 낮은 타워를 제거합니다.
        }

        // 스택이 비어있지 않으면, 맨 위 타워가 대상 타워입니다.
        if (stk.size() > 0) {
            targetTowerIndex = stk.top().index;
        }

        // 현재 타워의 대상 타워 인덱스를 설정합니다.
        t.setTargetTowerIndex(targetTowerIndex);

        // 현재 타워를 스택에 푸시합니다.
        stk.push(t);
    }
}

// 메인 함수입니다.
int main() {
    int n; // 타워의 수
    cin >> n; // 타워의 수를 입력합니다.

    vector<Tower> towers; // 타워 객체를 저장하는 벡터입니다.

    // 각 타워의 높이를 입력하고 타워 객체를 생성합니다.
    for (int i = 0; i < n; ++i) {
        int hi; // 타워의 높이
        cin >> hi; // 타워의 높이를 입력합니다.
        towers.push_back(Tower(i + 1, hi)); // 타워 객체를 생성하고 벡터에 추가합니다.
    }

    // 각 타워의 대상 타워를 찾습니다.
    findTargetTowers(towers);

    // 각 타워의 대상 타워 인덱스를 출력합니다.
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " "; // 타워 인덱스 사이에 공백을 출력합니다.
        }
        Tower t = towers[i]; // 타워 객체를 가져옵니다.
        int targetIndex = t.getTargetTowerIndex(); // 대상 타워의 인덱스를 가져옵니다.
        cout << targetIndex; // 대상 타워의 인덱스를 출력합니다.
    }
}