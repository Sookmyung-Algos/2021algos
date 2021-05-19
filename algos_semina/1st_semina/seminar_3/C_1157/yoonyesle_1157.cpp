#include <iostream>
using namespace std;

int main() {
	char s[1000001];
	int check[27] = {0};
	scanf("%s", s);
	for(int i = 0; s[i]; ++i){
		if (s[i] >= 'a') {
			s[i] -= 'a' - 1;
			++check[s[i]];
		}
		else {
			s[i] -= 'A' - 1;
			++check[s[i]];
		}
	}
	int max = 0, max_i;
	for (int i = 0; s[i]; ++i){
		if (check[s[i]] > max) {
			max = check[s[i]];
			max_i = s[i];
		}
	}
	for (int i = 0; s[i]; ++i)
		if (check[s[i]] == max && s[i] != max_i) {
			printf("?");
			return 0;
		}
	printf("%c", max_i + 'A' - 1);
	return 0;
}
