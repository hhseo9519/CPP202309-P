#define _CRT_SECURE_NO_WARNINGS // Windows 환경에서 안전하지 않은 함수를 사용해도 경고를 표시하지 않음

#include <stdio.h> // 표준 입력 및 출력 함수 라이브러리
#include <vector> // 동적 배열을 위한 라이브러리
#include <algorithm> // 알고리즘 함수를 사용하기 위한 라이브러리

using namespace std; // 표준 라이브러리를 사용할 때 std:: 접두어 생략

// 가능한 타겟 값을 찾는 함수
vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
    vector<int> possibleTargets; // 가능한 타겟 값들을 저장할 동적 배열

    // 카드 배열을 오름차순으로 정렬
    sort(cards, cards + n);

    // 모든 타겟 값에 대해 탐색
    for (int i = 0; i < m; ++i)
    {
        int k = targets[i]; // 현재 타겟 값
        bool possible = false; // 가능한 조합을 찾았는지 여부

        // 카드 배열을 순회하며 가능한 조합을 찾음
        for (int j = 0; j < n; ++j)
        {
            int x = cards[j]; // 첫 번째 카드 숫자
            for (int p = 0; p <= j; p += 1)
            {
                int y = cards[p]; // 두 번째 카드 숫자
                int z = k - (x + y); // 가능한 세 번째 숫자 계산

                // 세 번째 숫자가 카드 배열에 존재하는지 확인
                if (binary_search(cards, cards + n, z))
                {
                    possible = true; // 가능한 조합을 찾았음을 표시
                    break; // 내부 루프 탈출
                }
            }
            if (possible) {//이미 가능한 조합을 찾았다면 외부 루프 탈출
                break;
            }
        }
        // 가능한 경우 타겟 값 배열에 추가
        if (possible) {
            possibleTargets.push_back(k);
        }
    }
    // 가능한 타겟 값들을 정렬하여 반환
    sort(possibleTargets.begin(), possibleTargets.end());
    return possibleTargets;
}

int main() {
    int n; // 카드 개수
    int m; // 타겟 개수

    // 카드 개수와 타겟 개수 입력
    scanf("%d %d", &n, &m);

    int* cards = new int[n]; // 카드 번호에 해당되는 배열 동적 할당
    int* targets = new int[m]; // 당첨번호에 해당되는 배열 동적 할당

    // 카드 번호 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // 당첨번호 입력
    for (int i = 0; i < m; i++) {
        scanf("%d", &targets[i]);
    }

    // 가능한 타겟 값들 찾기
    vector<int> answer = getPossibleTargets(n, m, cards, targets);

    // 결과 출력
    if (answer.size() == 0) // 가능한 타겟 값이 없는 경우
    {
        printf("NO"); // "NO"를 출력하여 아무것도 없음을 표시
    }
    else // 가능한 타겟 값이 있는 경우
    {
        for (int i = 0; i < answer.size(); i++) // 가능한 타겟 값들을 출력
        {
            if (i > 0) // 첫 번째 값을 제외한 경우에는 공백을 출력하여 숫자를 구분
            {
                printf(" ");
            }
            printf("%d", answer[i]); // 가능한 타겟 값을 출력
        }
    }

    // 동적 할당된 배열 해제
    delete[] cards;
    delete[] targets;

    return 0;
}