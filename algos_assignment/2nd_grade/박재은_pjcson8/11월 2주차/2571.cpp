#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[101][101]{ 0, };
	int max = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[x + j][y + k]++;
			}
		}
	}

	int areas = 0;

	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (arr[i][j] > 0) {
				int width = 1;
				int height = 1;

				for (int a = i; a < 101; a++) {
					if (arr[a][j] > 0) 
						width++;
					if (arr[a - 1][j] > 0 && arr[a][j] == 0) 
						break;
				}
				for (int a = j; a < 101; a++) {
					if (arr[i][a] > 0) 
						height++;
					if (arr[i][a - 1] > 0 && arr[i][a] == 0) 
						break;					
				}

				for (int w = i + width; w > i; w--) {
					for (int h = j + height; h > j; h--) {
						bool flag = true;
						for (int a = i; a < w; a++) {
							for (int b = j; b < h; b++) {
								if (arr[a][b] == 0) {
									flag = false;
									break;
								}
							} 
							if (!flag) break;
						}

						if (flag) {
							int area = (w - i) * (h - j);
							max = max > area ? max : area;
						}
					}
				}
			}
		}
	}
	cout << max;
}
