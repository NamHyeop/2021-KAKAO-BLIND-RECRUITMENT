#include <string>
#include <vector>
#include <iostream>
//3<=아이디의 길이<=15
//알파벳 소문자 숫자 - _  .
//. 처음과 끝 연속 사용불가

using namespace std;

string solution(string new_id) {
	string answer = "";

	
	//1단계
	int flag1 = 0;
	for (int i = 0; i<new_id.size(); i++)
	{

		if ('A' <= new_id[i] && new_id[i] <= 'Z')
		{
			answer += new_id[i] + 32;
			flag1 = 1;
		}
		else
		answer += new_id[i];
	}

	//2단계
	int flag2 = 0;
	string tmp2 = "";
	for (int i = 0; i < answer.size(); i++)
	{
		if (('a' <= answer[i] && answer[i] <= 'z') || (48 <= answer[i] && answer[i] <= 57) || (answer[i] == '.') || (answer[i] == '_') || (answer[i] == '-'))
		{
			tmp2 += answer[i];
		}
		else
			flag2 = 1;
	}
	answer = tmp2;

	//3단계
	int flag3 = 0;
	string tmp3 = "";
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == '.')
		{
			while (answer[i + 1] == '.')
			{
				i++;
				flag3 = 1;
			}
			tmp3 += answer[i];
		}
		else
		tmp3 += answer[i];
	}
	answer = tmp3;
	
	//4단계
	int flag4 = 0;
	string tmp4 = "";
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == '.' && i == 0 || (answer[i] == '.' && i == answer.size()-1))
		{
			flag4 = 1;
			continue;
		}
		else
		tmp4 += answer[i];
	}
	answer = tmp4;

	//5단계
	int flag5 = 0;
	if (answer == "")
	{
		flag5 = 1;
		answer += 'a';
	}
	
	//6단계
	int flag6 = 0;
	string tmp6 = "";
	if (answer.size() > 15)
	{
		flag6 = 1;

		for (int i = 0; i < 15; i++)
		{
			if (answer[i] == '.' && i == 14)
				continue;
			else{
				tmp6 += answer[i];
			}
		}
			answer = tmp6;
	}

	//7단계
	int flag7 = 0;
	
	if (answer.size() < 3)
	{
		flag7 = 1;
		while (answer.size() < 3)
			answer += answer.back();
	}

	/*
	if (flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0)
		cout << "1단계에서 7단계까지 거치는 동안 new_id(" << new_id << ")는 변하지 않습니다.즉, new_id가 처음부터 카카오의 아이디 규칙에 맞습니다" << endl;
	else
	{
		if (flag1 = 0)
			cout << "1단계 변화 없습니다." << endl;
		else
			cout << new_id << " ->" << answer1 << endl;

		if (flag2 == 0)
			cout << "2단계 변화 없습니다." << endl;
		else
			cout << answer1 << " ->" << tmp2 << endl;

		if (flag3 == 0)
			cout << "3단계 변화 없습니다." << endl;
		else
			cout << tmp2 << " ->" << tmp3 << endl;

		if (flag3 == 0)
			cout << "4단계 변화 없습니다." << endl;
		else
			cout << tmp3 << " ->" << tmp4 << endl;

		if (flag3 == 0)
			cout << "5단계 변화 없습니다." << endl;
		else
			cout << "" << " ->" << answer << endl;

		if (flag3 == 0)
			cout << "6단계 변화 없습니다." << endl;
		else
			cout << tmp4 << " ->" << tmp6 << endl;

		if (flag3 == 0)
			cout << "7단계 변화 없습니다." << endl;
		else
			cout << answer << " ->" << tmp7 << endl;
	}*/

	return answer;
}

int main(int argc, char *argv[])
{
	string key1 = "...!@BaT#*..y.abcdefghijklm";
	string key2 = "z-+.^.";
	string key3 = "=.=";
	string key4 = "123_.def";
	string key5 = "abcdefghijklmn.p";

	
	cout << solution(key1) << endl;
	cout << endl;
	cout << solution(key2) << endl;
	cout << endl;
	cout << solution(key3) << endl;
	cout << endl;
	cout << solution(key4) << endl;
	cout << endl;
	cout << solution(key5) << endl;


}
