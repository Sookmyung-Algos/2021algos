#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;


void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}



int main() {
	float cnt = 0;
	init();
	map<string, int> arr;
	string tree;
	while (getline(cin, tree)) {
		arr[tree]++;
		cnt++;
	}
	
	cout << fixed;
	cout.precision(4);
	for (auto i = arr.begin(); i != arr.end(); ++i) {
		float a = (i->second / cnt) * 100;
		cout << i->first << " " << a << "\n";
	}

	return 0;
}
