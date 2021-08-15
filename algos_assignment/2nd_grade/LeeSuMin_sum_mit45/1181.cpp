#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;

bool compare(string x, string y) {
	if (x.size() == y.size()) return x < y;
	return x.size() < y.size();
}

int main() {
	int n;
	cin >> n;

	words.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> words[i];
	//정렬
	sort(words.begin(), words.end(), compare);
	//중복 제거
	words.erase(unique(words.begin(), words.end()), words.end());

	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << "\n";
	return 0;
}
