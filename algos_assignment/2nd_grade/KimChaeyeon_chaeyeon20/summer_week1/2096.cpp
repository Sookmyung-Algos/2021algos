#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
int arr[100001][3];
int main() {
	init();
	int arrMax[3] = { 0 }, arrMin[3] = { 0 };
	int tempMax[3] = { 0 }, tempMin[3] = { 0 };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tempMax[j];
			tempMin[j] = tempMax[j];
			tempMax[j] += max(arrMax[1], (j == 1) ? max(arrMax[0], arrMax[2]) : arrMax[j]); 
			tempMin[j] += min(arrMin[1], (j == 1) ? min(arrMin[0], arrMin[2]) : arrMin[j]); 
		}
		memcpy(arrMax, tempMax, sizeof(int) * 3); 
		memcpy(arrMin, tempMin, sizeof(int) * 3);
	}
	sort(arrMax, arrMax + 3);
	sort(arrMin, arrMin + 3);
	cout << arrMax[2] << " " << arrMin[0] << endl;
	return 0;
}
