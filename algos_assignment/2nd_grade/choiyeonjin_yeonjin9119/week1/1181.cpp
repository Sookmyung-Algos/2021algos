#include <iostream>
#include <vector>//vector을 위해 헤더 선언
#include <algorithm>//sort를 위해 헤더 선언
using namespace std;
bool cmp(string a, string b) {//10814번 문제와 같이 정렬을 위한 cmp를 작성해줌
	if (a.size() == b.size()) {//크기가 같으면 알파벳 순 정렬
		return a < b;
	}
	else {
		return a.size() < b.size();//크기가 다르면 작은것 부터 정렬
	}
}
int main() {
	int n;
	vector<string> v;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {	
		cin >> str;
		v.push_back(str);//vector의 마지막에 str을 넣어줌
	}
	sort(v.begin(), v.end(), cmp);//처음부터 끝까지 정렬
	for (int k = 0; k < n; k++) {//만약 반복되는 단어가 있었다면, sort에서 정렬될 때 바로 앞과 뒤로 정렬되게 될테니 이를 이용해 중복단어를 제거하고 출력
		if (str == v[k]) {
			continue;
		}
		cout << v[k] << "\n";
		str = v[k];
	}
	return 0;
}
