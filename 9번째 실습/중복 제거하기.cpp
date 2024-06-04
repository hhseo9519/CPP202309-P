#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    // �Է� ���� ������ ������ ���� ����
    int n;
    // ������ �Է� ����
    scanf("%d", &n);
    // �ߺ��� üũ�ϱ� ���� set �ڷᱸ�� ����
    set<int> s;
    // ����� ������ ���� ����
    vector<string> results;

    // �Է� ���� ������ŭ �ݺ�
    for (int i = 0; i < n; i++) {
        int x;
        // ���� �Է� ����
        scanf("%d", &x);

        // �̹� ���� �������� Ȯ���Ͽ� ��� ����
        if (s.count(x) > 0) {
            results.push_back("DUPLICATED");
        }
        else {
            s.insert(x);
            results.push_back("OK");
        }
    }

    // ��� �Է��� ó���� �Ŀ� ����� �� ���� ���
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}