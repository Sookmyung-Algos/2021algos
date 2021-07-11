// baekjoon 11656 접미사 배열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string arr[1000];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
	string word;
	vector<string> strArr;
	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		strArr.push_back(word.substr(i,-1));
	}

	sort(strArr.begin(), strArr.end());

	for (int i = 0; i < strArr.size(); i++) {
		cout << strArr[i] << "\n";
	}
	return 0;
}
