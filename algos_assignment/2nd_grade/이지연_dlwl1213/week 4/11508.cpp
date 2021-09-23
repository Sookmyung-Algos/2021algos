//입력 받은 가격들 중 가장 비싼 것들부터 3개씩 묶었을 때 가장 저렴한 가격이 나옴->내림차순으로 가격을 정렬 후 인덱스에서 3을 나누었을 때 나머지가 2인 것들만 가격에 포함시키지 않으면 됨
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int n;
	int cost = 0;
	cin >> n;
	int *c = new int[n];
  
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
  
	sort(c, c + n, desc);
  
	for (int j = 0; j < n; j++) {
		if (j % 3 == 2) { //나머지가 2이면 포함시키지 않음
			continue;
		}
		cost += c[j];
	}
  
	cout << cost;
}
