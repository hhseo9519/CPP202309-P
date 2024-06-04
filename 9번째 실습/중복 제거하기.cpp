#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 입력 받을 개수를 저장할 변수 선언
    int n;
    // 개수를 입력 받음
    scanf("%d", &n);
    // 중복을 체크하기 위한 set 자료구조 선언
    set<int> s;
    // 결과를 저장할 벡터 선언
    vector<string> results;

    // 입력 받은 개수만큼 반복
    for (int i = 0; i < n; i++) {
        int x;
        // 숫자 입력 받음
        scanf("%d", &x);

        // 이미 나온 숫자인지 확인하여 결과 저장
        if (s.count(x) > 0) {
            results.push_back("DUPLICATED");
        }
        else {
            s.insert(x);
            results.push_back("OK");
        }
    }

    // 모든 입력을 처리한 후에 결과를 한 번에 출력
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}