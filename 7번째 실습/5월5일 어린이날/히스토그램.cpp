#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

// ������׷� Ŭ���� ����
class Histogram {
public:
    int height; // ������׷��� ����
    int leftX;  // ������׷��� ���� �� �ε���
    int rightX; // ������׷��� ������ �� �ε���

    // �⺻ ������
    Histogram() {}

    // �ε����� ���̸� �Է¹޴� ������
    Histogram(int index, int height) {
        this->leftX = index;                 // ������׷��� ���� �� �ε��� ����
        this->rightX = this->leftX + 1;      // ������׷��� ������ �� �ε��� ����
        this->height = height;               // ������׷��� ���� ����
    }
};

// ������׷����� ������ ���簢�� ������ �ִ� ���̸� ����ϴ� �Լ�
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
    long long answer = 0;           // �ִ� ���̸� �����ϴ� ����
    stack<Histogram> stk;           // ������ �̿��Ͽ� �ִ� ���� ���

    stk.push(Histogram(-1, 0));     // �ʱ�ȭ: ���� 0�� ������׷��� ���ÿ� ����
    for (int i = 0; i < histograms.size() + 1; i++) { // ������׷��� �� + 1�� �ݺ�
        Histogram h;                // ���� ������׷�
        if (i < histograms.size()) {
            h = histograms[i];      // ���� ������׷� ����
        }
        else {
            h = Histogram(histograms.size(), 0); // ������ �߰��� ���� ������׷�
        }
        while (stk.size() > 1 && stk.top().height > h.height) { // ������ top�� ���� ������׷����� ������
            Histogram lh = stk.top();   // ������ top ������׷�
            stk.pop();                  // ���ÿ��� ����
            Histogram bh = stk.top();   // �� ���� ������׷� (bottom ������׷�)

            long long width = abs(h.leftX - bh.rightX); // �ʺ� ���
            long long height = lh.height;              // ����
            long long area = width * height;            // ���� ���

            answer = max(answer, area); // �ִ� ���� ����
        }
        stk.push(h); // ���� ������׷� ���ÿ� ����
    }

    return answer; // �ִ� ���� ��ȯ
}

int main() {
    int caseSize;
    cin >> caseSize; // ���̽� �� �Է�

    vector<long long> answers; // �� ���̽��� ����� �����ϴ� ����
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { // ���̽� ����ŭ �ݺ�
        int n;
        cin >> n; // ������׷��� �� �Է�

        vector<Histogram> histograms; // ������׷����� �����ϴ� ����
        for (int i = 0; i < n; i++) { // ������׷��� ����ŭ �ݺ�
            int height;
            cin >> height; // ������׷��� ���� �Է�
            histograms.push_back(Histogram(i, height)); // ������׷� ���Ϳ� �߰�
        }

        long long answer = getLargestRectangleArea(histograms); // ������׷� ������ �ִ� ���� ���
        answers.push_back(answer); // ��� ���Ϳ� �߰�
    }

    // ��� ���̽��� ����� ���
    for (const auto& answer : answers) {
        cout << answer << endl;
    }

    return 0;
}