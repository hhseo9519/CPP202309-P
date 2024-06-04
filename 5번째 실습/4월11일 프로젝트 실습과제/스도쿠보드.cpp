#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
//최대값은 9로 설정
const int MAX_ROW = 9;
const int MAX_COL = 9;

class Sudokuboard {
public:
    // 인덱스를 행 번호로 변환하는 함수
    int getRowByIndex(int index) {
        return (index - 1) / 9 + 1;
    }

    // 인덱스를 열 번호로 변환하는 함수
    int getColByIndex(int index) {
        return (index - 1) % 9 + 1;
    }

    // 인덱스를 그룹 번호로 변환하는 함수
    int getGroupByIndex(int index) {
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        return getGroupByPosition(r, c);
    }

    // 행과 열 번호를 그룹 번호로 변환하는 함수
    int getGroupByPosition(int row, int column) {
        int left = ((row - 1) / 3) * 3 + 1;
        int offset = ((column - 1) / 3);
        return left + offset;
    }

    // 행과 열 번호를 인덱스로 변환하는 함수
    int getIndexByPosition(int row, int column) {
        return (row - 1) * 9 + (column - 1) % 9 + 1;
    }
};

// 결과를 출력하는 함수
void process(const vector<int>& indices) {
    Sudokuboard board; // Sudokuboard 클래스의 객체를 생성하여 보드 초기화

    // 주어진 인덱스에 대해 출력을 수행
    for (int index : indices) {
        // 출력할 row, col, group을 board의 함수를 통해 초기화
        int row = board.getRowByIndex(index); // 주어진 인덱스에 해당하는 행을 찾음
        int col = board.getColByIndex(index); // 주어진 인덱스에 해당하는 열을 찾음
        int group = board.getGroupByIndex(index); // 주어진 인덱스에 해당하는 그룹을 찾음

        // 결과 출력
        printf("case#%d:\n", index); // 현재 케이스의 인덱스를 출력
        printf("%d%d%d\n", row, col, group); // 해당 인덱스의 행, 열, 그룹을 출력
    }
}

int main() {
    int caseSize;//크기를 입력받음
    scanf("%d", &caseSize);

    vector<int> indices;
    // 입력받고 indices벡터에 집어 넣음
    for (int i = 0; i < caseSize; ++i) {
        int index;
        scanf("%d", &index);
        indices.push_back(index);
    }

    // 결과를 처리하고 출력
    process(indices);

    return 0;
}