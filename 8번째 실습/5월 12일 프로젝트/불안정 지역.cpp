#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// ���� Ŭ���� ����
class City {
public:
    int index; // ������ �ε���
    int income; // ������ ����

    // ������
    City(int index, int income) {
        this->index = index; // �ε��� �ʱ�ȭ
        this->income = income; // ���� �ʱ�ȭ
    }

    // ������ �������� �������� �� ������ �����ε�
    bool operator<(const City& o)const {
        return this->income < o.income;
    }

    // ������ �������� �������� �� ������ �����ε�
    bool operator>(const City& o) const {
        return this->income > o.income;
    }
};

// �ִ� ���� ���̸� ���ϴ� �Լ�
int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
    int answer = 0;

    // �ּ� ���� �ִ� �� ����
    priority_queue<City, vector<City>, greater<City>> rangeMinimum;
    priority_queue<City> rangeMaximum;

    // �ʱ� k-1�� ���ø� ������ ���� ����
    for (int i = 0; i < k - 1; i++) {
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]);
    }

    // �����̵� ������ ����� ����Ͽ� �ִ� ���� ���� ���
    for (int i = k - 1; i < n; i++) {
        rangeMaximum.push(cities[i]);
        rangeMinimum.push(cities[i]);

        // ������ ��� ���ø� ������ ����
        while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop();
        while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();

        // ���� �ִ� ���� ���� ����
        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
    }
    return answer;
}

// �� �׽�Ʈ ���̽� ó���ϴ� �Լ�
void process(int caseIndex) {
    int n, k;
    cin >> n >> k;
    vector<City> cities;

    // ���� ���� �Է�
    for (int i = 0; i < n; i += 1) {
        int income;
        cin >> income;
        cities.push_back(City(i, income)); // ���� ��ü �����Ͽ� ���Ϳ� �߰�
    }

    // �ִ� ���� ���� ���
    int answer = getMaximumRangeDifference(n, k, cities);

    // ��� ���
    cout << answer << endl;
}

// ���� �Լ�
int main() {
    int caseSize;
    cin >> caseSize;

    // �� �׽�Ʈ ���̽��� ���� ó��
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
    return 0;
}