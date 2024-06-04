#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    // �Է¹��� ���ڿ��� ���� N�� �Է¹޽��ϴ�.
    cin >> N;

    // ���ڿ��� �󵵸� ������ ���� �����մϴ�.
    map<string, int> frequencyMap;

    // ���� ���� �����ϴ� ���ڿ��� �󵵸� ������ ������ �ʱ�ȭ�մϴ�.
    int maxFrequency = 0;

    // N���� ���ڿ��� �Է¹޾� ó���մϴ�.
    for (int i = 0; i < N; i++) {
        string st;
        // ���ڿ� st�� �Է¹޽��ϴ�.
        cin >> st;
        // ���ڿ� st�� �󵵸� ������ŵ�ϴ�.
        frequencyMap[st]++;
        // ���� ���ڿ� st�� �󵵸� k�� �����մϴ�.
        int k = frequencyMap[st];
        // ���� ���ڿ� st�� �󵵰� maxFrequency���� ũ�� maxFrequency�� �����մϴ�.
        if (k > maxFrequency) {
            maxFrequency = k;
        }
    }

    // ���� ���� �����ϴ� ���ڿ��� �󵵸� ����մϴ�.
    cout << maxFrequency << endl;

    // ���� ��ȸ�ϸ� ���� ���� �����ϴ� �󵵸� ���� ���ڿ����� ����մϴ�.
    map<string, int>::iterator it;
    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        // ���� ���ڿ��� �󵵰� maxFrequency�� ������ ����մϴ�.
        if (it->second == maxFrequency) {
            printf("%s ", it->first.c_str());
        }
    }
}