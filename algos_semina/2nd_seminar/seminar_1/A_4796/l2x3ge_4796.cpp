#include<iostream>

using namespace std;

int main() {
	int L, P, V, idx = 1, result;
	cin >> L >> P >> V;
	while ((L != 0) && (P != 0) && (V != 0)) {
		result = (V / P)*L;
		if (V%P > L)
			result += L;
		else
			result += V % P;
		cout << "Case " << idx << ": " << result << "\n";
		idx++;
		cin >> L >> P >> V;
	}
	return 0;
}
