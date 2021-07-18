#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	
	vector <int> alp(26);
	string s;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int cnt = 1;
		for (int j = s.size() - 1; j >= 0; j--) //자리수 값 알아내기? (ABC이라 하면 A = 100, B = 10, C = 1)
		{
			alp[s[j] - 'A'] += cnt; 
			cnt *= 10;
		}
	}
	sort(alp.begin(), alp.end(), compare); //내림차순 정렬
	int num = 9;
	int ans = 0;

	for (int i = 0; i < 26; i++) //가장 큰 수 구하기
	{
		if (alp[i] == 0)
			break;

		ans += alp[i] * num;  
		num--;
	}

	cout << ans << endl;


}
