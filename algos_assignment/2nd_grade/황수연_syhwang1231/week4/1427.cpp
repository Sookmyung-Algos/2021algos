#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//내림차순
bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	vector<int> number;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		number.push_back(str.at(i)-'0');
	}

	sort(number.begin(), number.end(), compare);

	for (int i = 0; i < number.size(); i++)
		cout << number[i];
	return 0;
}
