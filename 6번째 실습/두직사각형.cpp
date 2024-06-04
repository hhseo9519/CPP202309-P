#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �� �簢���� �����ϴ� ������ ���̸� ����ϴ� �Լ�
int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)
{
    int l, r, t, b;
    // ������ �簢������ ����, ������, ��, �Ʒ��� ��ǥ �� �ִ밪�� ã��
    l = max(la, lb);
    r = min(ra, rb);
    t = min(ta, tb); // ���̰� ������ �� �� �����Ƿ� min ���� ���
    b = max(ba, bb);

    // ���� �� �簢���� ��ġ�� ������ �����Ѵٸ�
    if (l <= r && b <= t) {
        // ��ġ�� ������ ���̸� ����Ͽ� ��ȯ
        return (r - l) * (t - b);
    }
    // ��ġ�� ������ ���� ��� 0�� ��ȯ
    return 0;
}

// �׽�Ʈ ���̽��� �����ϴ� �Լ�
void test_case()
{
    int ax, ay, bx, by;
    int px, py, qx, qy;
    // �Է� �ޱ�
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    int la, ra, ba, ta; // ù ��° �簢���� ����, ������, �Ʒ�, �� ��ǥ
    la = min(ax, bx);
    ra = max(ax, bx); // �� ��ǥ �� ���� ���� ����, ū ���� ������
    ba = min(ay, by);
    ta = max(ay, by); // �� ��ǥ �� ���� ���� �Ʒ�, ū ���� ��

    int lb, rb, bb, tb; // �� ��° �簢���� ����, ������, �Ʒ�, �� ��ǥ
    lb = min(px, qx);
    rb = max(px, qx); // �� ��ǥ �� ���� ���� ����, ū ���� ������
    bb = min(py, qy);
    tb = max(py, qy); // �� ��ǥ �� ���� ���� �Ʒ�, ū ���� ��

    // �����ϴ� ������ ���� ���
    int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

    // ��� ���
    printf("%d\n", answer);
}

int main() {
    int t;
    // �׽�Ʈ ���̽� ���� �Է� �ޱ�
    scanf("%d", &t);

    // �� �׽�Ʈ ���̽��� ���� test_case �Լ� ȣ��
    for (int i = 0; i < t; i++) {
        test_case();
    }
    return 0; // ���α׷� ����
}