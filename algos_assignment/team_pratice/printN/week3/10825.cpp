#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct score {
	string name;
	int korean_sc, english_sc, math_sc;
};

bool cmp(score a, score b) {
	if (a.korean_sc == b.korean_sc && a.english_sc == b.english_sc && a.math_sc == b.math_sc)
		return a.name < b.name;
	if (a.korean_sc == b.korean_sc && a.english_sc == b.english_sc)
		return a.math_sc > b.math_sc;
	if (a.korean_sc == b.korean_sc)
		return a.english_sc < b.english_sc;
	return a.korean_sc > b.korean_sc;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<score> v(N);

	for (int i = 0; i < N; i++) 
		cin >> v[i].name >> v[i].korean_sc >> v[i].english_sc >> v[i].math_sc;

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) 
		cout << v[i].name << '\n';
}
