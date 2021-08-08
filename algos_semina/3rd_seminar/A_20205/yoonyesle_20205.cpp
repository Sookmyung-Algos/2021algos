#include <iostream>
using namespace std;

int main() {
	int n, k, pix[11][11];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &pix[i][j]);
	for (int i = 0; i < n * k; ++i) {
		for (int j = 0; j < n * k; ++j)
			printf("%d ", pix[i / k][j / k]);
		printf("\n");
	}
	return 0;
}
