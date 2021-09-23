#include <stdio.h>
#include <string.h>

int main() {
	char N[11] = { NULL };
	int temp;
	gets(N);

	for (int i = 0; i < strlen(N) - 1; i++) {
		for (int j = i; j < strlen(N); j++) {
			if (N[i] < N[j]) {
				temp = N[i];
				N[i] = N[j];
				N[j] = temp;
			}
		}
	}
	puts(N);
	return 0;
}
