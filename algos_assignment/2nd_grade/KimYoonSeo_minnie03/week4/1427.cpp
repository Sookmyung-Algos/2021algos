#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num, n[11],i=0;
	scanf("%d", &num);
	int pos = num;
	while (1) {
		n[i++] = (pos % 10);
		pos = pos / 10;
		if (pos == 0)
			break;
	}
	sort(n, n + i);
	for (int j = i-1; j >=0; j--)
		printf("%d", n[j]);
}
