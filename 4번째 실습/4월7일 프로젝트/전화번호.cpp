#define _CRT_SECURE_NO_WARNINGS // Visual Studio���� Ư�� �Լ��� ������� �߻��ϴ� ��� �����ϱ� ���� ��ó���� ���ù�

#include <cstdio> // ���� ����� �� ���˵� ������� ���� ǥ�� ���̺귯�� ��� ����

using namespace std;

const int MAX_TABLE_LENGTH = 10000; // ���̺� �迭�� �ִ� ���̸� �����ϴ� ���

// �־��� ������ �迭���� ������ �󵵸� ����Ͽ� �� ���̺� �����ϴ� �Լ�
void fillFrequencyTable(int data[], int n, int table[]) {
    int frequent_number = 0; // �󵵰� ���� ���� ���ڸ� �����ϴ� ����
    for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
        table[i] = 0; // ���̺� �ʱ�ȭ
    }
    for (int i = 0; i < n; i++) {
        frequent_number = data[i]; // ������ �迭�� ���� �����ͼ� frequent_number�� ����
        table[frequent_number] += 1; // �� ���̺��� �ش� ������ �� ����
    }
}

// ���� ����ϰ� ��Ÿ���� ���ڸ� ã�� �Լ�
int getFrequentNumber(int data[], int n) {
    int frequent_number = 0; // �󵵰� ���� ���� ���ڸ� �����ϴ� ����

    int table[MAX_TABLE_LENGTH]; // �� ���̺� �迭 ����
    fillFrequencyTable(data, n, table); // fillFrequencyTable �Լ� ȣ���Ͽ� �� ���̺� ����

    // �� ���̺��� ��ȸ�ϸ鼭 ���� ����ϰ� ��Ÿ���� ���ڸ� ã��
    for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
        if (table[i] > table[frequent_number]) {
            frequent_number = i; // �󵵰� �� ���� ���ڸ� frequent_number�� ����
        }
    }
    return frequent_number; // ���� ����ϰ� ��Ÿ���� ���� ��ȯ
}

int main() {
    int n; // ������ �迭�� ���̸� ������ ����

    scanf("%d", &n); // ����ڷκ��� ������ �迭�� ���� �Է¹���
    int* data = new int[n]; // ���̰� n�� ���� �迭 ���� �Ҵ�

    // ����ڷκ��� ������ �Է¹޾� �迭�� ����
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int answer = getFrequentNumber(data, n); // ���� ����ϰ� ��Ÿ���� ���ڸ� ã��

    printf("%04d", answer); // ��� ���

    delete[] data; // �������� �Ҵ�� �޸� ����

    return 0;
}