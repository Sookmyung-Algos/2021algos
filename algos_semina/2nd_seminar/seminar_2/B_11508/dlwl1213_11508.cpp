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
  
	sort(c, c + n, desc); //내림차순으로 가격 정렬
  
	for (int j = 0; j < n; j++) {
		if (j % 3 == 2) {  //3으로 나눴을 때 나머지가 2인 것들은 포함시키지 
			continue;
		}
		cost += c[j];
	}
	cout << cost;
  
  return 0;
}
