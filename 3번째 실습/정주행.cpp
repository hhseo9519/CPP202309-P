#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

// ������������ ���θ� �Ǻ��ϴ� �Լ�
bool isConsecutive(int data[], int n) {
    int max_data = data[0]; // �ִ밪 �ʱ�ȭ
    int min_data = data[0]; // �ּҰ� �ʱ�ȭ

    // �ִ밪�� �ּҰ� ã��
    for (int i = 0; i < n; i++) {
        if (max_data < data[i]) {
            max_data = data[i]; // �ִ밪 ����
        }
        if (min_data > data[i]) {
            min_data = data[i]; // �ּҰ� ����
        }
    }

    // �������� ���� �Ǻ�
    if (max_data - min_data == n - 1) { // �ִ밪�� �ּҰ� ���̰� n-1�̸� ��������
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;//�Է¹��� �������� ������ ������ ���� ����
    int* data;

    scanf("%d", &n); // ������ ���� �Է� �ޱ�
    data = new int[n]; // ������ �迭 ���� �Ҵ�

    // ������ �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // �������� ���� �Ǻ�
    bool result = isConsecutive(data, n);

    // ��� ���
    if (result) {
        printf("YES"); // ���������̸� YES ���
    }
    else {
        printf("NO"); // ���������� �ƴϸ� NO ���
    }

    delete[] data; // ���� �Ҵ�� �迭 �޸� ����
    return 0;
}