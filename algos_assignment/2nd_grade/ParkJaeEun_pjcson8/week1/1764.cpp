#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	set<string> s1;
	set< string> s2;
	string s;
    int count = 0;

	for (int i = 0; i < n; ++i) //듣도 못한 사람 입력받기
	{
		cin >> s;
		s1.insert(s);
	}

	for (int i = 0; i < m; ++i) //보도 못한 사람 입력받기
	{
		cin >> s;
		s2.insert(s);
	}

	vector<string> v; //vertor 선언
	set<string>::iterator it; //iterator 사용

	for (auto i = s1.begin(); i != s1.end(); i++)
	{
		it = s2.find(*i); //동일한 값이 없으면 s.end() 반환
		if (it != s2.end()) { //동일한 값이 존재하는 경우
			v.push_back(*it); //벡터 v의 마지막에 삽입.
			count++;
		}
	}

	cout << count << '\n'; //듣도 보도 못한 이름 개수 출력
	for (int i = 0; i < v.size(); i++) //듣보잡 이름 출력.
	{
		cout << v[i] << '\n';
	}

	return 0;
}
