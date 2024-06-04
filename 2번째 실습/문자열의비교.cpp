#define _CRT_SECURE_NO_WARNINGS 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_LENGTH = 10000;
//���ڿ��� ��ü�� ��ȯ�Ͽ� ���غ����� ��
class MyString {
private:
    char* characters; // ���ڿ��� �����ϴ� ���� �迭 ������
    int length; // ���ڿ��� ���̸� �����ϴ� ����
public:
    // ���ڿ��� �Է����� �޾� MyString ��ü�� �����ϴ� ������
    MyString(const char* str)
    {
        this->length = strlen(str); // �Է� ���ڿ��� ���� ���� ���
        this->characters = new char[this->length + 1]; // ���ڿ� ������ ���� null���ڸ� �����Ͽ� �޸� ���� �Ҵ�
        strcpy(this->characters, str); // �Է� ���ڿ��� �����Ͽ� ����
    }

    // �Ҹ���: ���� �Ҵ�� �޸𸮸� ����
    ~MyString()
    {
        delete[] characters; // ���ڿ��� �����ϴ� �迭�� �޸� ����
    }

    // MyString ��ü�� ������� ���ڿ� �� ������ (<)
    bool operator < (const MyString& o) const {
        int minLength = min(this->length, o.length); // �� ���ڿ��� �ּ� ���� ���
        for (int i = 0; i < minLength; i++) {
            if (this->characters[i] != o.characters[i]) { // �� ���� ��
                return this->characters[i] < o.characters[i]; // �ٸ� ������ �� ������ ���� ��ȯ
            }
        }
        return this->length < o.length; // ��� ���ڰ� ���ٸ� ���� ��
    }

    // MyString ��ü�� ������� ���ڿ� �� ������ (>)
    bool operator > (const MyString& o) const {
        return o < *this; // ���� �� �����ڸ� ����Ͽ� ū�� ���� ��ȯ
    }

    // MyString ��ü ���� ���� �� ������ (==)
    bool operator == (const MyString& o)const {
        if (this->length != o.length) { // ���̰� �ٸ� ���
            return false; // �ٸ� ���ڿ��� ����
        }
        for (int i = 0; i < this->length; i++) {
            if (this->characters[i] != o.characters[i]) { // �� ���� ��
                return false; // �ٸ� ���ڿ��� ����
            }
        }
        return true; // ��� ���ڰ� ���ٸ� ������ ���ڿ��� ����
    }
};

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2; // �� ���ڿ� �Է� ����
    MyString mys1(s1.c_str()); // ù ��° ���ڿ��� MyString ��ü�� ��ȯ
    MyString mys2(s2.c_str()); // �� ��° ���ڿ��� MyString ��ü�� ��ȯ

    if (mys1 < mys2) // ù ��° ���ڿ��� ���� ���
    {
        printf("-1"); // -1 ���
    }
    else if (mys1 > mys2) // ù ��° ���ڿ��� ū ���
    {
        printf("1"); // 1 ���
    }
    else { // �� ���ڿ��� ���� ���
        printf("0"); // 0 ���
    }
    return 0;
}