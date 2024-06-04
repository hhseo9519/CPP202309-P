#define _CRT_SECURE_NO_WARNINGS // Visual Studio���� scanf ��� ���� ��� �����ϱ� ���� ��ó�� ���ù�

#include<cstdio> // scanf �� printf�� ���� C ǥ�� ����� ���̺귯���� ����
#include<vector> // C++ ǥ�� ���ø� ���̺귯��(STL)�� vector �����̳� ����
#include<algorithm> // C++ STL�� �˰��� �Լ����� ����

using namespace std; // ǥ�� ���̺귯�� �Լ��� ��ü�� std::�� ������ �ʰ� ����ϱ� ���� using ���ù�

const int MAX_SERIAL_NUMBER = 100000; // ������ �ִ� �ø��� ��ȣ�� ��Ÿ���� ���

// �������� ��Ұ� �߻��ϴ� �󵵸� ����ϴ� �Լ�
void fillFrequencyTable(const vector<int>& data, int n, vector<int>& table) {
    table.clear(); // ���̺� ���͸� ����
    table.resize(MAX_SERIAL_NUMBER + 1, 0); // ���̺� ���� ũ�⸦ �����ϰ� ��� ��Ҹ� 0���� �ʱ�ȭ

    // ������ ���͸� �ݺ�
    for (int i = 0; i < n; ++i) {
        int serial = data[i]; // �������� �ε��� i�� �ִ� �ø��� ��ȣ�� ������
        table[serial] += 1; // ���̺� �ִ� �ø��� ��ȣ�� ī��Ʈ�� ����
    }
}

// �����Ϳ��� ������ ��Ҹ� ã�� �Լ�
vector<int> getUniqueElements(const vector<int>& data, int n) {
    vector<int> ret; // ������ ��Ҹ� �����ϱ� ���� ����

    vector<int> table; // ����� �󵵸� �����ϱ� ���� ����
    fillFrequencyTable(data, n, table); // �� ���̺� ä���

    // ������ �ø��� ��ȣ�� �ݺ�
    for (int number = 1; number <= MAX_SERIAL_NUMBER; number = +1) {
        // ��ȣ�� �󵵰� 1�� ���, ������
        if (table[number] == 1) {
            ret.push_back(number); // ������ ��ȣ�� ��ȯ ���Ϳ� �߰�
        }
    }
    return ret; // ������ ��Ҹ� �����ϴ� ���� ��ȯ
}

int main() {
    int n;
    scanf("%d", &n); // ������ �迭�� ũ�⸦ ����

    vector<int> data = vector<int>(n); // �����͸� �����ϱ� ���� ũ�� n�� ���� ����

    // ������ �迭 ��Ҹ� ����
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]); // �� ��Ҹ� ������ ���Ϳ� �о����
    }

    const vector<int> answer = getUniqueElements(data, n); // �����Ϳ��� ������ ��� ã��

    // ������ ��Ҹ� ���
    for (int i = 0; i < answer.size(); ++i) {
        if (i > 0) {
            printf(" "); // ��� ���̿� ���� ���
        }
        printf("%d", answer[i]); // ���� ��� ���
    }
    return 0; // ���α׷��� ���������� �Ϸ�Ǿ����� ��Ÿ��
}