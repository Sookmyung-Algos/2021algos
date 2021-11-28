#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	printf("%s", n % 7 == 0 || n % 7 == 2 ? "CY" : "SK");
	return 0;
}
