#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector <int> v; //벡터 선언
	cin >> n; //몇 개의 수를 받을 지를 변수 n에 저장

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num); //벡터에 n개의 수 저장
	}

	sort(v.begin(), v.end()); //퀵정렬의 경우 시간복잡도가 최악인 경우 O(n^2)까지 커지므로 백준에서 시간초과 발생. sort함수를 통해 정렬

	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n'; //정렬 결과 출력
	}

	return 0;
}
