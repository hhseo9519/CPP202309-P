#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// ��ȣ Ŭ���� ����
class Parenthesis {
public:
    bool type;  // ��ȣ ���� (���� ��ȣ���� �ݴ� ��ȣ����)
    int index;  // ��ȣ�� �ε���

    // �ε����� ������ �޾ƿͼ� �ʱ�ȭ�ϴ� ������
    Parenthesis(int index, bool type) {
        this->index = index;
        this->type = type;
    }

    // �ε����� ���ڸ� �޾ƿͼ� ������ �Ǻ��Ͽ� �ʱ�ȭ�ϴ� ������
    Parenthesis(int index, char c) {
        this->index = index;
        if (c == '(') { // '('�� ���
            this->type = true; // ���� ��ȣ
        }
        else { // ')'�� ���
            this->type = false; // �ݴ� ��ȣ
        }
    }
};

// ��ȣ���� ��ȿ���� �˻��ϴ� �Լ�
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
    stack<Parenthesis> st; // ������ ����Ͽ� ��ȣ���� ����

    // ��ȣ���� �ݺ��ϸ鼭 �˻�
    for (int i = 0; i < parentheses.size(); i++) {
        Parenthesis p = parentheses[i]; // ���� ��ȣ

        if (p.type == true) { // ���� ��ȣ�� ���
            st.push(p); // ���ÿ� �߰�
        }
        else if (p.type == false) { // �ݴ� ��ȣ�� ���
            if (st.size() > 0) { // ������ ������� ������
                st.pop(); // ¦�� �´� ���� ��ȣ�� ��
            }
            else { // ������ ���������
                return false; // ��ȣ�� ��ȿ���� ����
            }
        }
    }

    if (st.size() > 0) { // ���ÿ� �����ִ� ��ȣ�� �ִ� ���
        return false; // ��ȣ�� ��ȿ���� ����
    }

    return true; // ��� ��ȣ�� ¦�� �¾� ��ȿ��
}

// ���� �Լ�
int main() {
    int caseSize; // �׽�Ʈ ���̽��� ��
    cin >> caseSize; // �׽�Ʈ ���̽��� �� �Է�
    cin.ignore(); // caseSize ������ ������ ���� ���� ����

    vector<string> inputs(caseSize); // �׽�Ʈ ���̽����� ������ ����

    // �׽�Ʈ ���̽��� �Է¹���
    for (int i = 0; i < caseSize; ++i) {
        getline(cin, inputs[i]); // �� �پ� �Է¹���
    }

    // �� �׽�Ʈ ���̽����� ����
    for (const auto& str : inputs) {
        vector<Parenthesis> parentheses; // ��ȣ���� ������ ����

        // ���ڿ��� �� ���ڿ� ���� ��ȣ ��ü�� �����Ͽ� ���Ϳ� �߰�
        for (int i = 0; i < str.length(); ++i) {
            parentheses.push_back(Parenthesis(i, str[i])); // �ε����� ���ڷ� ��ȣ ��ü ����
        }

        // �ش� �׽�Ʈ ���̽��� ��ȣ ��ȿ�� �˻�
        bool isValid = isValidParentheses(parentheses);

        // ��ȣ ��ȿ���� ���� ��� ���
        if (isValid) {
            cout << "YES" << endl; // ��ȿ�� ��� "YES" ���
        }
        else {
            cout << "NO" << endl; // ��ȿ���� ���� ��� "NO" ���
        }
    }

    return 0; // ���α׷� ����
}