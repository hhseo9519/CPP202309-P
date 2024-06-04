#include <cstdio>
#include <vector>
#include <unordered_map> // �ؽ� ���� ����ϱ� ���� ��� ����

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class TicketTable {
public:
    vector<bool> used; // ��� ���θ� �����ϴ� ����
    int length; // Ƽ�� ���̺��� ���̸� ������ ���� ����

    // ������: Ƽ�� ���̺� �ʱ�ȭ
    TicketTable(int length) {
        this->length = length;
        this->used.assign(length, false); // ��� Ƽ���� �̻�� ���·� �ʱ�ȭ
    }

    // ����� ID�� ������� �� Ƽ�� �ε����� ã�� �Լ�
    int findEmptyIndexByUserId(int userId) {
        int index = userId % length; // ����� ID�� Ƽ�� �ε����� ��ȯ
        while (this->isEmpty(index) == true) {
            index = (index + 1) % length; // �浹 �߻� �� ���� Ž�縦 ���� ���� �ε����� �̵�
        }
        return index;
    }

    // Ư�� �ε����� Ƽ���� ��� �������� Ȯ���ϴ� �Լ�
    bool isEmpty(int ticketIndex) {
        return this->used[ticketIndex];
    }

    // Ư�� �ε����� Ƽ�� ��� ���θ� �����ϴ� �Լ�
    void setUsed(int index, bool status) {
        this->used[index] = status;
    }
};

// ����� ID�� ������� Ƽ���� �Ҵ��ϴ� �Լ�
vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
    vector<int> tickets;
    TicketTable table = TicketTable(n); // Ƽ�� ���̺� ����

    for (int i = 0; i < m; i++) {
        int userId = ids[i];
        int ticketIndex = table.findEmptyIndexByUserId(userId); // ����� ID�� ������� �� Ƽ�� �ε��� ã��
        tickets.push_back(ticketIndex); // �Ҵ�� Ƽ�� �ε��� ����
        table.setUsed(ticketIndex, true); // �ش� Ƽ���� ������� ǥ��
    }
    return tickets; // �Ҵ�� Ƽ�� �ε��� ��ȯ
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m); // Ƽ�� ���̺��� ���̿� ����� �� �Է�

    vector<int> ids(m); // ����� ID�� �����ϴ� ����

    for (int i = 0; i < m; i++) {
        scanf("%d", &ids[i]); // ����� ID �Է�
    }

    // Ƽ�� �Ҵ� �� ���
    vector<int> tickets = getTicketNumbers(n, m, ids);
    for (int i = 0; i < m; ++i) {
        printf("%d\n", tickets[i]); // �� ������� Ƽ�� ���
    }
}