#define _CRT_SECURE_NO_WARNINGS 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_LENGTH = 10000;
//문자열을 객체로 변환하여 비교해보도록 함
class MyString {
private:
    char* characters; // 문자열을 저장하는 문자 배열 포인터
    int length; // 문자열의 길이를 저장하는 변수
public:
    // 문자열을 입력으로 받아 MyString 객체를 생성하는 생성자
    MyString(const char* str)
    {
        this->length = strlen(str); // 입력 문자열의 실제 길이 계산
        this->characters = new char[this->length + 1]; // 문자열 저장을 위해 null문자를 포함하여 메모리 동적 할당
        strcpy(this->characters, str); // 입력 문자열을 복사하여 저장
    }

    // 소멸자: 동적 할당된 메모리를 해제
    ~MyString()
    {
        delete[] characters; // 문자열을 저장하는 배열의 메모리 해제
    }

    // MyString 객체로 만들어진 문자열 비교 연산자 (<)
    bool operator < (const MyString& o) const {
        int minLength = min(this->length, o.length); // 두 문자열의 최소 길이 계산
        for (int i = 0; i < minLength; i++) {
            if (this->characters[i] != o.characters[i]) { // 각 문자 비교
                return this->characters[i] < o.characters[i]; // 다른 문자일 때 작은지 여부 반환
            }
        }
        return this->length < o.length; // 모든 문자가 같다면 길이 비교
    }

    // MyString 객체로 만들어진 문자열 비교 연산자 (>)
    bool operator > (const MyString& o) const {
        return o < *this; // 작은 비교 연산자를 사용하여 큰지 여부 반환
    }

    // MyString 객체 간의 동등 비교 연산자 (==)
    bool operator == (const MyString& o)const {
        if (this->length != o.length) { // 길이가 다른 경우
            return false; // 다른 문자열로 간주
        }
        for (int i = 0; i < this->length; i++) {
            if (this->characters[i] != o.characters[i]) { // 각 문자 비교
                return false; // 다른 문자열로 간주
            }
        }
        return true; // 모든 문자가 같다면 동일한 문자열로 간주
    }
};

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2; // 두 문자열 입력 받음
    MyString mys1(s1.c_str()); // 첫 번째 문자열을 MyString 객체로 변환
    MyString mys2(s2.c_str()); // 두 번째 문자열을 MyString 객체로 변환

    if (mys1 < mys2) // 첫 번째 문자열이 작은 경우
    {
        printf("-1"); // -1 출력
    }
    else if (mys1 > mys2) // 첫 번째 문자열이 큰 경우
    {
        printf("1"); // 1 출력
    }
    else { // 두 문자열이 같은 경우
        printf("0"); // 0 출력
    }
    return 0;
}