#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Tower Ŭ������ �� Ÿ���� ��Ÿ���ϴ�.
class Tower {
public:
    int index;              // Ÿ���� �ε���
    int height;             // Ÿ���� ����
    int targetTowerIndex;   // ��� Ÿ���� �ε���

    // �����ڴ� Ÿ�� ��ü�� �ε����� ���̷� �ʱ�ȭ�մϴ�.
    Tower(int index, int height) {
        this->index = index;
        this->height = height;
        this->targetTowerIndex = 0; // ��� Ÿ���� �ε����� 0���� �ʱ�ȭ�մϴ�.
    }

    // ��� Ÿ���� �ε����� �����ϴ� �޼����Դϴ�.
    void setTargetTowerIndex(int targetTowerIndex) {
        this->targetTowerIndex = targetTowerIndex;
    }

    // ��� Ÿ���� �ε����� ��ȯ�ϴ� �޼����Դϴ�.
    int getTargetTowerIndex() {
        return this->targetTowerIndex;
    }
};

// �� Ÿ���� ��� Ÿ���� ã�� �Լ��Դϴ�.
void findTargetTowers(vector<Tower>& towers) {
    stack<Tower> stk; // Ÿ���� �����ϴ� �����Դϴ�.

    // �� Ÿ���� �ݺ��մϴ�.
    for (int i = 0; i < towers.size(); i++) {
        Tower& t = towers[i]; // ���� Ÿ���� ���� �����Դϴ�.

        int targetTowerIndex = 0; // ��� Ÿ���� �ε��� (0���� �ʱ�ȭ)

        // ������ ������� �ʰ�, ������ �� �� Ÿ���� ���� Ÿ������ ���� ������ Ÿ���� ���մϴ�.
        while (stk.empty() == false && stk.top().height < t.height) {
            stk.pop(); // ���ÿ��� �� ���� Ÿ���� �����մϴ�.
        }

        // ������ ������� ������, �� �� Ÿ���� ��� Ÿ���Դϴ�.
        if (stk.size() > 0) {
            targetTowerIndex = stk.top().index;
        }

        // ���� Ÿ���� ��� Ÿ�� �ε����� �����մϴ�.
        t.setTargetTowerIndex(targetTowerIndex);

        // ���� Ÿ���� ���ÿ� Ǫ���մϴ�.
        stk.push(t);
    }
}

// ���� �Լ��Դϴ�.
int main() {
    int n; // Ÿ���� ��
    cin >> n; // Ÿ���� ���� �Է��մϴ�.

    vector<Tower> towers; // Ÿ�� ��ü�� �����ϴ� �����Դϴ�.

    // �� Ÿ���� ���̸� �Է��ϰ� Ÿ�� ��ü�� �����մϴ�.
    for (int i = 0; i < n; ++i) {
        int hi; // Ÿ���� ����
        cin >> hi; // Ÿ���� ���̸� �Է��մϴ�.
        towers.push_back(Tower(i + 1, hi)); // Ÿ�� ��ü�� �����ϰ� ���Ϳ� �߰��մϴ�.
    }

    // �� Ÿ���� ��� Ÿ���� ã���ϴ�.
    findTargetTowers(towers);

    // �� Ÿ���� ��� Ÿ�� �ε����� ����մϴ�.
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " "; // Ÿ�� �ε��� ���̿� ������ ����մϴ�.
        }
        Tower t = towers[i]; // Ÿ�� ��ü�� �����ɴϴ�.
        int targetIndex = t.getTargetTowerIndex(); // ��� Ÿ���� �ε����� �����ɴϴ�.
        cout << targetIndex; // ��� Ÿ���� �ε����� ����մϴ�.
    }
}