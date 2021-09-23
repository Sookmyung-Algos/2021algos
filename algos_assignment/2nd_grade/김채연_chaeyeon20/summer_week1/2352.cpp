#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#define MAX 20001
using namespace std;

int arr[40001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector <int> vect;
	vect.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (vect.back() < arr[i]) vect.push_back(arr[i]);
		else {
			int pos = lower_bound(vect.begin(), vect.end(), arr[i]) - vect.begin();
			vect[pos] = arr[i];

		}
	}
	cout << vect.size();
	return 0;

}
