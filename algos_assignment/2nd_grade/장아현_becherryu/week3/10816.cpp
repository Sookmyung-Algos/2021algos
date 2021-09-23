//이분탐색변형 lower_bound(<=), upper_bound(<)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //시간초과해결
	cin.tie(NULL);
	cin.tie(NULL);
	
	int n, m;
	vector <int> v;
	

	cin >> n; //개수
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end()); //오름차순정렬

	cin >> m; //값
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;

		cout << upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key) << " "; //카드개수구하기('이상 - 초과'의 수 구해서 출력)
	}
}
