#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> v2;

int main() {

	int student;

	cin >> student;

	for (int i = 0; i < 2 * student; i++) {
		int a;

		cin >> a;

		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int length = v.size();

	for (int i = 0; i < student; i++) {
		v2.push_back(v[i] + v[length - i -1]);
	}

	sort(v2.begin(), v2.end());

	cout << v2[0];

}
