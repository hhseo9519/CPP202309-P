#include <iostream> 
#include <iomanip>
#include <vector> 
#include <cmath>
#include <set>
using namespace std;

// 2���� ���� ��Ÿ���� Ŭ���� ����
class Point2D {
public:
    int x; // x ��ǥ
    int y; // y ��ǥ
    int index; // ���� �ε���

    // ������: �ε����� ��ǥ���� �޾� Point2D ��ü�� �ʱ�ȭ
    Point2D(int index, int x, int y) {
        this->index = index;
        this->x = x;
        this->y = y;
    }

    // ������: ��ǥ���� �޾� Point2D ��ü�� �ʱ�ȭ. �ε����� �⺻������ ����
    Point2D(int x, int y) {
        this->index = 1;
        this->x = x;
        this->y = y;
    }

    // �� �� ������ �Ÿ��� ������ ����ϴ� �޼���
    long long getSquaredDistanceTo(Point2D target) {
        long long dx = abs(this->x - target.x);
        long long dy = abs(this->y - target.y);
        return dx * dx + dy * dy;
    }

    // �� �� ������ �Ÿ��� ����ϴ� �޼���
    double getDistanceTo(Point2D target) {
        long long sqd = this->getSquaredDistanceTo(target);
        return sqrt(sqd);
    }

    // ������ ���� �� �����ڸ� ����
    bool operator<(const Point2D& other) const {
        if (this->x != other.x) {
            return this->x < other.x;
        }
        return this->y < other.y;
    }
};

// �ִ� �簢�� ���̸� ���ϴ� �Լ�
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0;
    set<Point2D> pSet;

    // �Էµ� ������ set�� ����
    for (int i = 0; i < n; i += 1) {
        pSet.insert(points[i]);
    }

    // ��� �� �ֿ� ���� �簢���� ���� �� �ִ��� Ȯ��
    for (int i = 0; i < n; i += 1) {
        Point2D pa = points[i];
        for (int j = 0; j < n; j += 1) {
            Point2D pb = points[j];

            if (i == 0) {
                continue;
            }

            long long area = pa.getSquaredDistanceTo(pb);

            if (area < answer) {
                continue;
            }

            int dx = pb.x - pa.x;
            int dy = pb.y - pa.y;

            Point2D pd(pa.x - dy, pa.y + dx);
            Point2D pc(pb.x - dy, pb.y + dx);

            if (pSet.count(pc) > 0 && pSet.count(pd) > 0) {
                answer = max(answer, area);
            }
        }
    }

    return answer;
}

// �� ���̽��� ó���ϰ� ����� �����ϴ� �Լ�
void process(int caseIndex, vector<double>& results) {
    int n;
    cin >> n;

    vector<Point2D> points;

    // ������ �Է� �޾� Point2D ��ü�� ����
    for (int i = 0; i < n; i += 1) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point2D(i, x, y));
    }

    // �ִ� �簢�� ���̸� ����Ͽ� ��� ���Ϳ� ����
    double answer = getMaximumSquareArea(n, points);
    results.push_back(answer);
}

int main() {
    int caseSize;
    cin >> caseSize;
    vector<double> results;

    // �� ���̽��� ó���ϰ� ����� ���Ϳ� ����
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex, results);
    }

    // ����� ���
    for (double result : results) {
        cout << fixed << setprecision(2) << result << endl;
    }

    return 0;
}