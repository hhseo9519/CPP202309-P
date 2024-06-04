#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// 괄호 클래스 정의
class Parenthesis {
public:
    bool type;  // 괄호 종류 (여는 괄호인지 닫는 괄호인지)
    int index;  // 괄호의 인덱스

    // 인덱스와 종류를 받아와서 초기화하는 생성자
    Parenthesis(int index, bool type) {
        this->index = index;
        this->type = type;
    }

    // 인덱스와 문자를 받아와서 종류를 판별하여 초기화하는 생성자
    Parenthesis(int index, char c) {
        this->index = index;
        if (c == '(') { // '('인 경우
            this->type = true; // 여는 괄호
        }
        else { // ')'인 경우
            this->type = false; // 닫는 괄호
        }
    }
};

// 괄호들의 유효성을 검사하는 함수
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
    stack<Parenthesis> st; // 스택을 사용하여 괄호들을 저장

    // 괄호들을 반복하면서 검사
    for (int i = 0; i < parentheses.size(); i++) {
        Parenthesis p = parentheses[i]; // 현재 괄호

        if (p.type == true) { // 여는 괄호인 경우
            st.push(p); // 스택에 추가
        }
        else if (p.type == false) { // 닫는 괄호인 경우
            if (st.size() > 0) { // 스택이 비어있지 않으면
                st.pop(); // 짝이 맞는 여는 괄호를 팝
            }
            else { // 스택이 비어있으면
                return false; // 괄호가 유효하지 않음
            }
        }
    }

    if (st.size() > 0) { // 스택에 남아있는 괄호가 있는 경우
        return false; // 괄호가 유효하지 않음
    }

    return true; // 모든 괄호가 짝이 맞아 유효함
}

// 메인 함수
int main() {
    int caseSize; // 테스트 케이스의 수
    cin >> caseSize; // 테스트 케이스의 수 입력
    cin.ignore(); // caseSize 다음에 나오는 개행 문자 제거

    vector<string> inputs(caseSize); // 테스트 케이스들을 저장할 벡터

    // 테스트 케이스들 입력받음
    for (int i = 0; i < caseSize; ++i) {
        getline(cin, inputs[i]); // 한 줄씩 입력받음
    }

    // 각 테스트 케이스마다 실행
    for (const auto& str : inputs) {
        vector<Parenthesis> parentheses; // 괄호들을 저장할 벡터

        // 문자열의 각 문자에 대해 괄호 객체를 생성하여 벡터에 추가
        for (int i = 0; i < str.length(); ++i) {
            parentheses.push_back(Parenthesis(i, str[i])); // 인덱스와 문자로 괄호 객체 생성
        }

        // 해당 테스트 케이스의 괄호 유효성 검사
        bool isValid = isValidParentheses(parentheses);

        // 괄호 유효성에 따라 결과 출력
        if (isValid) {
            cout << "YES" << endl; // 유효한 경우 "YES" 출력
        }
        else {
            cout << "NO" << endl; // 유효하지 않은 경우 "NO" 출력
        }
    }

    return 0; // 프로그램 종료
}