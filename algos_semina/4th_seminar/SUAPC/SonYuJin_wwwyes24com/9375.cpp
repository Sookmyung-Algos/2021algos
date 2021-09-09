#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int t, n, res = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {  // 각 테케별로
		map<string, int> clothes;
		cin >> n;
		for (int j = 0; j < n; j++) { // 의상 입력
			string name, ctg;
			cin >> name >> ctg;
			clothes[ctg]++;
		}

		for (auto cnt = clothes.begin(); cnt != clothes.end(); cnt++) 
			res *= (cnt->second + 1); // 안입는 경우 포함
		
		cout << res - 1<<"\n";
		res = 1;
	}
}
