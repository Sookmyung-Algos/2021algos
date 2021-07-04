#include <iostream>
using namespace std;

int L, P, V, i;
int main() {
	do {
		i++;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}

		cout << "Case " << i << ": " << (V / P) * L + min(V % P, L) << "\n";
	} while (1);
	return 0;
}
