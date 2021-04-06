#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

int main()
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	string tree;
	float count = 0; //입력받는 tree 수

	while (getline(cin, tree))
	{
		if (m.find(tree) != m.end()) //입력받은 tree가 이미 존재할 경우
			m[tree] += 1;
		else //입력받은 tree가 처음인 경우
			m[tree] = 1;

		count++;
	}
	cout << fixed;
	cout.precision(4); //소수점 넷째자리까지 출력

	for (auto iter = m.begin();iter != m.end(); iter++)
	{
		float percent = (iter->second / count) * 100; //비율 계산
		cout << iter->first << " " << percent << '\n'; // tree 이름 / 비율 출력
	}
	return 0;
}
