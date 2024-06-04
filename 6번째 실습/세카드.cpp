#define _CRT_SECURE_NO_WARNINGS // Windows ȯ�濡�� �������� ���� �Լ��� ����ص� ��� ǥ������ ����

#include <stdio.h> // ǥ�� �Է� �� ��� �Լ� ���̺귯��
#include <vector> // ���� �迭�� ���� ���̺귯��
#include <algorithm> // �˰��� �Լ��� ����ϱ� ���� ���̺귯��

using namespace std; // ǥ�� ���̺귯���� ����� �� std:: ���ξ� ����

// ������ Ÿ�� ���� ã�� �Լ�
vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
    vector<int> possibleTargets; // ������ Ÿ�� ������ ������ ���� �迭

    // ī�� �迭�� ������������ ����
    sort(cards, cards + n);

    // ��� Ÿ�� ���� ���� Ž��
    for (int i = 0; i < m; ++i)
    {
        int k = targets[i]; // ���� Ÿ�� ��
        bool possible = false; // ������ ������ ã�Ҵ��� ����

        // ī�� �迭�� ��ȸ�ϸ� ������ ������ ã��
        for (int j = 0; j < n; ++j)
        {
            int x = cards[j]; // ù ��° ī�� ����
            for (int p = 0; p <= j; p += 1)
            {
                int y = cards[p]; // �� ��° ī�� ����
                int z = k - (x + y); // ������ �� ��° ���� ���

                // �� ��° ���ڰ� ī�� �迭�� �����ϴ��� Ȯ��
                if (binary_search(cards, cards + n, z))
                {
                    possible = true; // ������ ������ ã������ ǥ��
                    break; // ���� ���� Ż��
                }
            }
            if (possible) {//�̹� ������ ������ ã�Ҵٸ� �ܺ� ���� Ż��
                break;
            }
        }
        // ������ ��� Ÿ�� �� �迭�� �߰�
        if (possible) {
            possibleTargets.push_back(k);
        }
    }
    // ������ Ÿ�� ������ �����Ͽ� ��ȯ
    sort(possibleTargets.begin(), possibleTargets.end());
    return possibleTargets;
}

int main() {
    int n; // ī�� ����
    int m; // Ÿ�� ����

    // ī�� ������ Ÿ�� ���� �Է�
    scanf("%d %d", &n, &m);

    int* cards = new int[n]; // ī�� ��ȣ�� �ش�Ǵ� �迭 ���� �Ҵ�
    int* targets = new int[m]; // ��÷��ȣ�� �ش�Ǵ� �迭 ���� �Ҵ�

    // ī�� ��ȣ �Է�
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // ��÷��ȣ �Է�
    for (int i = 0; i < m; i++) {
        scanf("%d", &targets[i]);
    }

    // ������ Ÿ�� ���� ã��
    vector<int> answer = getPossibleTargets(n, m, cards, targets);

    // ��� ���
    if (answer.size() == 0) // ������ Ÿ�� ���� ���� ���
    {
        printf("NO"); // "NO"�� ����Ͽ� �ƹ��͵� ������ ǥ��
    }
    else // ������ Ÿ�� ���� �ִ� ���
    {
        for (int i = 0; i < answer.size(); i++) // ������ Ÿ�� ������ ���
        {
            if (i > 0) // ù ��° ���� ������ ��쿡�� ������ ����Ͽ� ���ڸ� ����
            {
                printf(" ");
            }
            printf("%d", answer[i]); // ������ Ÿ�� ���� ���
        }
    }

    // ���� �Ҵ�� �迭 ����
    delete[] cards;
    delete[] targets;

    return 0;
}