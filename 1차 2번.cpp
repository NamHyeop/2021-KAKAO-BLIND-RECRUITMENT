//단품메뉴로 가장많이시킨 단품메뉴
//코스메뉴는 최소 2가지 이상(가장많이시킨단품메뉴로)

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	
	vector<string> test;
	string allalpha ="";

	for (int i = 0; i < orders.size(); i++)
	{
		string Testorder = orders[i];
		for (int i = 0; i < Testorder.size(); i++)
		{
			if (allalpha.find(Testorder[i]) == -1)
				allalpha += Testorder[i];
		}
	}


	
	sort(answer.begin(), answer.end());


	return answer;
}

int main()
{
	vector<string> orders;
	vector<int> course;
	vector<string> ret;
	orders.push_back("ABCDE");
	orders.push_back("AB");
	orders.push_back("CD");
	orders.push_back("ADE");
	orders.push_back("XYZ");
	orders.push_back("ACD");
	course.push_back(2);
	course.push_back(3);
	course.push_back(5);

	ret = solution(orders, course);

	/*
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}*/
}

/*
orders.push_back("ABCDE");
orders.push_back("AB");
orders.push_back("CD");
orders.push_back("ADE");
orders.push_back("XYZ");
orders.push_back("ACD");
*/
