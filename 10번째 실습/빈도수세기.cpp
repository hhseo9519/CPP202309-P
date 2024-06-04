#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    // �Է¹��� ������ ���� N�� �Է¹޽��ϴ�.
    cin >> N;

    // ������ �󵵸� ������ ���� �����մϴ�.
    map<int, int> frequencyMap;

    // N���� ������ �Է¹޾� ó���մϴ�.
    for (int i = 0; i < N; i++) {
        int X;
        // ���� X�� �Է¹޽��ϴ�.
        cin >> X;
        // ���� X�� �󵵸� ������ŵ�ϴ�.
        frequencyMap[X]++;
        // ���� �ʿ� �ִ� ���� �ٸ� ������ ������ ���� X�� �󵵸� ����մϴ�.
        cout << frequencyMap.size() << " " << frequencyMap[X] << endl;
    }

    // �ּ� �κ��� Ȱ��ȭ�Ͽ� ���� ��� ������ ����մϴ�.
    map<int, int>::iterator it;
    // ���� ��ȸ�ϸ� �� Ű-�� ���� ����մϴ�.
    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}