#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;   
int main() {
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {  //벡터에 x,y값 삽입을 5번 반복
		cin >> x >> y;
		v.push_back(make_pair(x, y));  
	}
	sort(v.begin(), v.end());     //정렬
	for (int i = 0; i < n; i++) {     //정렬된 순서대로 출력
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	
}
