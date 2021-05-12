#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> name;
bool binary(string key) {
	int s = 0, e = name.size() - 1;
	int mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (name[mid] > key) {
			e = mid - 1;
		}
		else if (name[mid] < key) s = mid + 1;
		else return true;
	}
	return false;
}
int main() {
	int n;
	int m;

	cin >> n >> m;
	vector <string> result;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		name.push_back(a);
	}
	sort(name.begin(), name.end());
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (binary(str)) {
			result.push_back(str);
		}
	}
	sort(result.begin(), result.end());
	int t = result.size();
	cout << t << endl;
	for (int i = 0; i < t; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
