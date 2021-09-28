#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int num;
	
	scanf("%d\n", &num);

	vector<vector<int>> xy(num, vector<int>(2, 0));

	for (int i = 0; i < num; i++)
		scanf("%d %d\n", &xy[i][0], &xy[i][1]);

	sort(xy.begin(), xy.end());

	for (int j = 0; j < num; j++)
		printf("%d %d\n", xy[j][0], xy[j][1]);
	
}
