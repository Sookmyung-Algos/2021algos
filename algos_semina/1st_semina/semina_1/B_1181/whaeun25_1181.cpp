#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string> alpha;

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;

		alpha.push_back(s);
	}

	sort(alpha.begin(), alpha.end(), cmp);
	alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());

	for (int i = 0; i < alpha.size(); i++) {
		cout << alpha[i] << "\n";
	}


}
