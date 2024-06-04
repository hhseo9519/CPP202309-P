#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    // 입력받을 문자열의 개수 N을 입력받습니다.
    cin >> N;

    // 문자열의 빈도를 저장할 맵을 선언합니다.
    map<string, int> frequencyMap;

    // 가장 자주 등장하는 문자열의 빈도를 저장할 변수를 초기화합니다.
    int maxFrequency = 0;

    // N개의 문자열을 입력받아 처리합니다.
    for (int i = 0; i < N; i++) {
        string st;
        // 문자열 st를 입력받습니다.
        cin >> st;
        // 문자열 st의 빈도를 증가시킵니다.
        frequencyMap[st]++;
        // 현재 문자열 st의 빈도를 k에 저장합니다.
        int k = frequencyMap[st];
        // 현재 문자열 st의 빈도가 maxFrequency보다 크면 maxFrequency를 갱신합니다.
        if (k > maxFrequency) {
            maxFrequency = k;
        }
    }

    // 가장 자주 등장하는 문자열의 빈도를 출력합니다.
    cout << maxFrequency << endl;

    // 맵을 순회하며 가장 자주 등장하는 빈도를 가진 문자열들을 출력합니다.
    map<string, int>::iterator it;
    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        // 현재 문자열의 빈도가 maxFrequency와 같으면 출력합니다.
        if (it->second == maxFrequency) {
            printf("%s ", it->first.c_str());
        }
    }
}