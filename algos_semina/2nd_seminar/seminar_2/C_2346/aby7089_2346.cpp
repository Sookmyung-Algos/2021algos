#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair <int, int>> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, total = 0, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		v.push_back(pair<int, int>(i, k));
	}
	int val;
	while (!v.empty()) { //begin,end는 주소값  front,back은 요소
		cout << v.front().first << " ";
		val = v.front().second;
		v.erase(v.begin());
		if (v.empty()) break;
		if (val < 0) { //값이 0보다 작으면 맨 뒤에 것을 앞으로 보냄
			for (int i = 0; i < (-1)*(val); i++) {  //val<0이므로 조건문에선 양수로 만들어야 함
				v.insert(v.begin(), v.back());
				v.erase(v.end() - 1);
			}
		}
		else {  //값이 0보다 크면 맨 앞에 것을 뒤로 보냄
			for (int i = 0; i < val - 1; i++) {
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
	}
}
