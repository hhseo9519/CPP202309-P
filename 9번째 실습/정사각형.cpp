#include <iostream> 
#include <iomanip>
#include <vector> 
#include <cmath>
#include <set>
using namespace std;

// 2차원 점을 나타내는 클래스 정의
class Point2D {
public:
    int x; // x 좌표
    int y; // y 좌표
    int index; // 점의 인덱스

    // 생성자: 인덱스와 좌표값을 받아 Point2D 객체를 초기화
    Point2D(int index, int x, int y) {
        this->index = index;
        this->x = x;
        this->y = y;
    }

    // 생성자: 좌표값만 받아 Point2D 객체를 초기화. 인덱스는 기본값으로 설정
    Point2D(int x, int y) {
        this->index = 1;
        this->x = x;
        this->y = y;
    }

    // 두 점 사이의 거리의 제곱을 계산하는 메서드
    long long getSquaredDistanceTo(Point2D target) {
        long long dx = abs(this->x - target.x);
        long long dy = abs(this->y - target.y);
        return dx * dx + dy * dy;
    }

    // 두 점 사이의 거리를 계산하는 메서드
    double getDistanceTo(Point2D target) {
        long long sqd = this->getSquaredDistanceTo(target);
        return sqrt(sqd);
    }

    // 정렬을 위한 비교 연산자를 정의
    bool operator<(const Point2D& other) const {
        if (this->x != other.x) {
            return this->x < other.x;
        }
        return this->y < other.y;
    }
};

// 최대 사각형 넓이를 구하는 함수
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0;
    set<Point2D> pSet;

    // 입력된 점들을 set에 저장
    for (int i = 0; i < n; i += 1) {
        pSet.insert(points[i]);
    }

    // 모든 점 쌍에 대해 사각형을 만들 수 있는지 확인
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

// 각 케이스를 처리하고 결과를 저장하는 함수
void process(int caseIndex, vector<double>& results) {
    int n;
    cin >> n;

    vector<Point2D> points;

    // 점들을 입력 받아 Point2D 객체로 저장
    for (int i = 0; i < n; i += 1) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point2D(i, x, y));
    }

    // 최대 사각형 넓이를 계산하여 결과 벡터에 저장
    double answer = getMaximumSquareArea(n, points);
    results.push_back(answer);
}

int main() {
    int caseSize;
    cin >> caseSize;
    vector<double> results;

    // 각 케이스를 처리하고 결과를 벡터에 저장
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex, results);
    }

    // 결과를 출력
    for (double result : results) {
        cout << fixed << setprecision(2) << result << endl;
    }

    return 0;
}