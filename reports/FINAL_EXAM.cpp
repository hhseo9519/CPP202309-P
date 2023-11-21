#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	//프로그램 참여 신청받기
	cout << "매칭 프로그램에 참여하시겠습니까?(Y/N) : ";
	char OX;
	cin >> OX;
	if (OX != 'y' || OX != 'Y') {
		cout << "환영합니다!";
	}
	else {
		cout << "프로그램을 종료하겠습니다!!";
		return 0;
	}

	while (true)
	{
	cout << "참여자의 정보를 입력하시오 " << endl;
	cout << "이름 : " << endl;
	cin >>
}
}
