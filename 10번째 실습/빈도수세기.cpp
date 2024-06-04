#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    // 입력받을 정수의 개수 N을 입력받습니다.
    cin >> N;

    // 정수의 빈도를 저장할 맵을 선언합니다.
    map<int, int> frequencyMap;

    // N개의 정수를 입력받아 처리합니다.
    for (int i = 0; i < N; i++) {
        int X;
        // 정수 X를 입력받습니다.
        cin >> X;
        // 정수 X의 빈도를 증가시킵니다.
        frequencyMap[X]++;
        // 현재 맵에 있는 서로 다른 정수의 개수와 정수 X의 빈도를 출력합니다.
        cout << frequencyMap.size() << " " << frequencyMap[X] << endl;
    }

    // 주석 부분을 활성화하여 맵의 모든 내용을 출력합니다.
    map<int, int>::iterator it;
    // 맵을 순회하며 각 키-값 쌍을 출력합니다.
    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}