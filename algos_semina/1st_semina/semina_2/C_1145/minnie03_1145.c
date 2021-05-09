#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int five[5];
int num = 1;

int main() {
	scanf("%d %d %d %d %d", &five[0], &five[1], &five[2], &five[3], &five[4]);
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (num % five[i] == 0)
				cnt++;
		}
		if (cnt >= 3)
			break;
		num++;
	}
	printf("%d", num);
	return 0;
}
