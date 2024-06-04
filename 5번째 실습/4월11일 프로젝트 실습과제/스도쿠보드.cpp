#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
//�ִ밪�� 9�� ����
const int MAX_ROW = 9;
const int MAX_COL = 9;

class Sudokuboard {
public:
    // �ε����� �� ��ȣ�� ��ȯ�ϴ� �Լ�
    int getRowByIndex(int index) {
        return (index - 1) / 9 + 1;
    }

    // �ε����� �� ��ȣ�� ��ȯ�ϴ� �Լ�
    int getColByIndex(int index) {
        return (index - 1) % 9 + 1;
    }

    // �ε����� �׷� ��ȣ�� ��ȯ�ϴ� �Լ�
    int getGroupByIndex(int index) {
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        return getGroupByPosition(r, c);
    }

    // ��� �� ��ȣ�� �׷� ��ȣ�� ��ȯ�ϴ� �Լ�
    int getGroupByPosition(int row, int column) {
        int left = ((row - 1) / 3) * 3 + 1;
        int offset = ((column - 1) / 3);
        return left + offset;
    }

    // ��� �� ��ȣ�� �ε����� ��ȯ�ϴ� �Լ�
    int getIndexByPosition(int row, int column) {
        return (row - 1) * 9 + (column - 1) % 9 + 1;
    }
};

// ����� ����ϴ� �Լ�
void process(const vector<int>& indices) {
    Sudokuboard board; // Sudokuboard Ŭ������ ��ü�� �����Ͽ� ���� �ʱ�ȭ

    // �־��� �ε����� ���� ����� ����
    for (int index : indices) {
        // ����� row, col, group�� board�� �Լ��� ���� �ʱ�ȭ
        int row = board.getRowByIndex(index); // �־��� �ε����� �ش��ϴ� ���� ã��
        int col = board.getColByIndex(index); // �־��� �ε����� �ش��ϴ� ���� ã��
        int group = board.getGroupByIndex(index); // �־��� �ε����� �ش��ϴ� �׷��� ã��

        // ��� ���
        printf("case#%d:\n", index); // ���� ���̽��� �ε����� ���
        printf("%d%d%d\n", row, col, group); // �ش� �ε����� ��, ��, �׷��� ���
    }
}

int main() {
    int caseSize;//ũ�⸦ �Է¹���
    scanf("%d", &caseSize);

    vector<int> indices;
    // �Է¹ް� indices���Ϳ� ���� ����
    for (int i = 0; i < caseSize; ++i) {
        int index;
        scanf("%d", &index);
        indices.push_back(index);
    }

    // ����� ó���ϰ� ���
    process(indices);

    return 0;
}