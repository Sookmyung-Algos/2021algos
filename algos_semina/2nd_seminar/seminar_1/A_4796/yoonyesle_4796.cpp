#include <iostream>
using namespace std;

int main() {
	int a, b, c, i = 1;
	for(int i = 1;; ++i){
		scanf("%d%d%d", &a, &b, &c);
		if(!a) break;
		if(c % b < a) printf("Case %d: %d\n", i, c / b * a + c % b);
		else printf("Case %d: %d\n", i, c / b * a + a);
	}
	return 0;
}
