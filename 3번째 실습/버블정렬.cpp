#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

// ���� ���� �Լ�
void bubbleSort(int data[], int n) {
    for (int i = 0; i < n; i++) { // �迭�� ��� ��ҿ� ���� �ݺ�
        int negativecount = 0; // ������ �Ϸ�Ǿ����� Ȯ���ϱ� ���� ���� �ʱ�ȭ
        for (int j = 0; j < n - 1 - i; j++) { // �迭�� ��Ҹ� ���ϸ� ����
            if (data[j] > data[j + 1]) { // ���� ��ҿ� ���� ��Ҹ� ���Ͽ� ������ �ʿ��� ���
                int temp = data[j]; // �� ��Ҹ� ��ȯ
                data[j] = data[j + 1];
                data[j + 1] = temp;
                negativecount++; // ������ �̷�������� ǥ��
            }
        }
        if (negativecount == 0) { // ������ �� �̻� �ʿ����� ���� ���
            break; // �ݺ� ����
        }
    }
}

int main() {
    int n; // �Է� ���� �������� ����
    int* data; // �Է� ���� �����͸� ������ �迭 ������

    scanf("%d", &n); // �������� ���� �Է� �ޱ�
    data = new int[n]; // �迭 ���� �Ҵ�

    // ������ �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n); // ������ ����

    // ���ĵ� ������ ���
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // ù ��° �����͸� �����ϰ� ���� ���
        }
        printf("%d", data[i]); // ������ ���
    }

    delete[] data; // ���� �Ҵ�� �迭 �޸� ����
    return 0;
}