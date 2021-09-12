#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) { 
	if (a.length() == b.length())	return a < b; //길이가 같은 경우 사전순
	return a.length() < b.length(); //길이가 다른 경우 짧은 순서대로
}
int main() {
	int n;
	cin >> n;

	vector<string> v;
	while (n--) {
		string temp;
		cin >> temp;
		if (find(v.begin(), v.end(), temp)==v.end())	v.push_back(temp);
		//find함수는 범위 안에서 temp와 일치하는 첫 번째 원소를 가리키는 반복자 리턴
		//찾지 못할 경우 last 리턴
	}
	
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < v.size(); i++)	cout << v[i] << '\n';

	return 0;
}
