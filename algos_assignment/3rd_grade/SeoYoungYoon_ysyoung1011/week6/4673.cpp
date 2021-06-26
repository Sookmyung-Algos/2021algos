#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v;
	for (int i = 1; i <= 10000; i++) {
		int num = i, temp = i, flag = 1;
		while (temp > 0) {
			if (num > 10000) {
				flag = 0;
				break;
			}
			num += temp % 10;
			temp /= 10;
		}
		if (flag==1) v.push_back(num);
	}
	for (int i = 1; i <= 10000; i++) {
		auto it = find(v.begin(), v.end(), i);
		if (it == v.end()) cout << i<<"\n";
	}
}
