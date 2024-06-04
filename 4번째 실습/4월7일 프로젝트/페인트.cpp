#define _CRT_SECURE_NO_WARNINGS // Visual Studio���� scanf ��� ���� ��� �����ϱ� ���� ��ó�� ���ù�

#include <cstdio> // C ǥ�� ����� ���̺귯��
#include <vector> // C++ ǥ�� ���̺귯���� vector ����

using namespace std; // ǥ�� ���̺귯�� �Լ��� ��ü�� std::�� ������ �ʰ� ����ϱ� ���� using ���ù�

const int MAX_SEAT_NUMBER = 1000; // ������ �ִ� �¼� ��ȣ
const int MAX_COLOR_NUMBER = 100; // ������ �ִ� ���� ��ȣ

// �׸� Ŭ���� ����
class Painting {
public:
    int left; // �׸��� ���� �¼� ��ȣ
    int right; // �׸��� ������ �¼� ��ȣ
    int color; // �׸��� ����

    // �⺻ ������
    Painting() {}

    // �ʱ�ȭ ������
    Painting(int left, int right, int color) {
        this->left = left;
        this->right = right;
        this->color = color;
    }
};

// �������� �󵵸� �����ϴ� �Լ�
void fillFrequencyTable(int data[], int n, int table[]) {
    // ���̺� �迭 �ʱ�ȭ
    for (int i = 0; i < MAX_COLOR_NUMBER; i++) {
        table[i] = 0;
    }

    // ������ �迭�� �ݺ��ϸ� �� ���̺� ä���
    for (int i = 0; i < n; i++) {
        int color = data[i];
        table[color] += 1;
    }
}

// ���� �ذ��� ���� �Լ�
void solve(int n, int m, const Painting* paintings) {
    int* seats = new int[n]; // �¼� �迭 ���� �Ҵ� �� �ʱ�ȭ

    // �¼� �迭 �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        seats[i] = 0;
    }

    // �׸� �迭�� �ݺ��ϸ� �¼� �迭�� ���� �Ҵ�
    for (int i = 0; i < m; i++) {
        const Painting& p = paintings[i];

        // �׸��� ���ʺ��� �����ʱ��� �¼��� ���� �Ҵ�
        for (int j = p.left; j <= p.right; j++) {
            seats[j] = p.color;
        }
    }

    int* table = new int[MAX_COLOR_NUMBER]; // �� ���̺��� ������ �迭 ���� �Ҵ�
    fillFrequencyTable(seats, n, table); // �¼� �迭�κ��� �� ���̺� ä���

    int minColor = seats[0]; // �ּ� �󵵸� ���� ���� �ʱ�ȭ
    int maxColor = seats[0]; // �ִ� �󵵸� ���� ���� �ʱ�ȭ

    // �� ���̺��� ��ȸ�ϸ� �ּ� �󵵿� �ִ� �󵵸� ���� ���� ã��
    for (int color = 0; color < MAX_COLOR_NUMBER; color += 1) {
        if (table[color] == 0) {
            continue; // �ش� ������ ������ ���� ��� ���� �������� �Ѿ
        }

        // ���� ������ �ּ� �󵵸� ���� ���󺸴� �� ���� �󵵸� ������ ��� �ּ� �󵵸� ���� ���� ����
        if (table[minColor] > table[color]) {
            minColor = color;
        }

        // ���� ������ �ִ� �󵵸� ���� ���󺸴� �� ���� �󵵸� ������ ��� �ִ� �󵵸� ���� ���� ����
        if (table[maxColor] < table[color]) {
            maxColor = color;
        }
    }

    // �ִ� �󵵸� ���� ����� �ּ� �󵵸� ���� ���� ���
    printf("%d\n", maxColor);
    printf("%d\n", minColor);

    delete[] table; // ���� �Ҵ��� �� ���̺� �޸� ��ȯ
}

// ���� �Լ�
int main() {
    int n, m;
    scanf("%d %d", &n, &m); // �¼� ���� �׸� �� �Է¹���

    Painting* paintings = new Painting[n]; // �׸� �迭 ���� �Ҵ�

    // �׸� ���� �Է�
    for (int i = 0; i < m; i++) {
        scanf("%d", &paintings[i].left); // �׸��� ���� �¼� ��ȣ �Է�
        scanf("%d", &paintings[i].right); // �׸��� ������ �¼� ��ȣ �Է�
        scanf("%d", &paintings[i].color); // �׸��� ���� �Է�

        paintings[i].left -= 1; // �¼� ��ȣ�� 0���� �����ϹǷ� 1�� ����
        paintings[i].right -= 1; // �¼� ��ȣ�� 0���� �����ϹǷ� 1�� ����
    }

    solve(n, m, paintings); // ���� �ذ� �Լ� ȣ��

    return 0; // ���α׷� ���� ����
}