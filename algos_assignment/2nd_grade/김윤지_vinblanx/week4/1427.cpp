#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string n;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n.size(); i++) {
		v.push_back(n[i] - '0'); //문자상수를 숫자로 바꿔준 뒤, n개의 수를 벡터에 푸쉬
	}
	sort(v.begin(), v.end()); //벡터 오름차순 정렬
	reverse(v.begin(), v.end()); //정렬된 벡터 뒤집기

	for (int i = 0; i < n.size(); i++) {
		cout << v[i]; //출력
	}
}
