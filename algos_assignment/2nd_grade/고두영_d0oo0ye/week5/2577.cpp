#include <stdio.h>

int main() {
  
	int a, b, c, z, i, o;
	int n[10] = { 0 };

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	z = a * b * c;

	while (z != 0) {
		o = z % 10;
		n[o] += 1;
		z /= 10;
	}

	for (i = 0; i < 10; i++) {
		printf("%d\n", n[i]);
	}

	return 0;
}
