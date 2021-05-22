#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a, b;
	int rate[51];
	vector<pair<int, int>> dungchi;

	cin >> n;
	for (int i = 0; i < n; i++)
		rate[i] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		dungchi.push_back({ a,b });
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dungchi[i].first > dungchi[j].first && dungchi[i].second > dungchi[j].second) 
				rate[j]++;
			
			else if (dungchi[i].first < dungchi[j].first && dungchi[i].second < dungchi[j].second)
				rate[i]++;
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << rate[i]<<" ";
}
