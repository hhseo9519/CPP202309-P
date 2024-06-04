#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include<climits> // INT_MAX ����� ����ϱ� ���� ����
#include<cmath> // sqrt �Լ��� ����ϱ� ���� ����
using namespace std;

class point2D {
private:
    int x; // x ��ǥ
    int y; // y ��ǥ
public:
    point2D(int x = 0, int y = 0) { // ������, �⺻���� (0, 0)
        this->x = x;
        this->y = y;
    }
    int getSquareDistanceTo(const point2D& target) const { // �� �� ������ �Ÿ��� ������ ��ȯ�ϴ� �޼���
        int dx = this->x - target.x; // x ��ǥ ����
        int dy = this->y - target.y; // y ��ǥ ����
        return dx * dx + dy * dy; // �Ÿ��� ���� ��ȯ
    }
    double getDistanceTo(const point2D& target) const { // �� �� ������ �Ÿ��� ��ȯ�ϴ� �޼���
        double sqd = (double)getSquareDistanceTo(target); // �Ÿ��� ����
        return sqrt(sqd); // ������ ��ȯ
    }

};

int main() {
    int n; // ���� ����
    point2D* points; // �� ��ü �迭 ������

    scanf("%d", &n); // ���� ���� �Է� �ޱ�
    points = new point2D[n]; // �� ��ü �迭 ���� �Ҵ�

    for (int i = 0; i < n; i++) { // �� ���� ��ǥ �Է� �ޱ�
        int x, y; // x, y ��ǥ
        scanf("%d %d", &x, &y); // x, y ��ǥ �Է� �ޱ�

        points[i] = point2D(x, y); // �� ��ü �迭�� ��ǥ ����
    }

    int min_sqd = INT_MAX; // �ּ� �Ÿ��� ����, �ʱⰪ�� �������� �ִ밪
    int min_cnt = 0; // �ּ� �Ÿ��� ����, �ʱⰪ�� 0

    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { // ���� ������ ���������� üũ
            int sqd = points[i].getSquareDistanceTo(points[j]); // �� �� ������ �Ÿ��� ���� ���
            if (sqd < min_sqd) { // ���� �Ÿ��� ������ �ּ� �Ÿ��� �������� ������ �ּ� �Ÿ� ������
                min_sqd = sqd; // �ּ� �Ÿ� ������
                min_cnt = 1; // �ּ� �Ÿ� ���� �ʱ�ȭ
            }
            else if (sqd == min_sqd) { // ���� �Ÿ��� ������ �ּ� �Ÿ��� ������ ������ �ּҰŸ��� ������ ������Ŵ
                min_cnt++; // �ּ� �Ÿ� ���� ����
            }
        }
    }

    double distance = sqrt(min_sqd); // �ּ� �Ÿ��� �������� ����
    printf("%.1f\n", distance); // �Ҽ��� ù° �ڸ����� ���
    printf("%d\n", min_cnt); // �ּ� �Ÿ��� ���� ���

    delete[] points; // ���� �Ҵ�� �޸� ����
    return 0;
}