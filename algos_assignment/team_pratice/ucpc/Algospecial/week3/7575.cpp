#include <iostream>
#include <vector>
using namespace std;

int pi[1001], pi_rev[1001];

bool kmp(vector<int> &virus, vector<int> &program) {
	for (int i = 0, j = 0; i < program.size(); ++i) {
		// cout << i << " " << j << endl;
		while (j && virus[j] != program[i])
			j = pi[j - 1];
		if (virus[j] == program[i]) {
			if (j == virus.size() - 1)
				return true;
			++j;
		}
	}
	return false;
}

bool kmp_rev(vector<int> &virus, vector<int> &program) {
	for (int i = 0, j = 0; i < program.size(); ++i) {
		while (j && virus[j] != program[i])
			j = pi_rev[j - 1];
		if (virus[j] == program[i]) {
			if (j == virus.size() - 1)
				return true;
			++j;
		}
	}
	return false;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> program[101];
	for (int i = 0; i < n; ++i) {
		int size, tmp;
		scanf("%d", &size);
		while (size--) {
			scanf("%d", &tmp);
			program[i].push_back(tmp);
		}
	}
	vector<int> virus, virus_rev;
	int isVirus;
	for (int i = 0; i <= program[0].size() - k; ++i) {
		virus.clear(); virus_rev.clear();
		for (int j = i; j < i + k; ++j)
			virus.push_back(program[0][j]);
		for (int j = i + k - 1; j >= i; --j)
			virus_rev.push_back(program[0][j]);
		isVirus = true;
		for (int p = 1, q = 0; p < k; ++p) {
			while (q && virus[p] != virus[q])
				q = pi[q - 1];
			if (virus[p] == virus[q])
				pi[p] = ++q;
			else
				pi[p] = 0;
		}
		for (int p = 1, q = 0; p < k; ++p) {
			while (q && virus_rev[p] != virus_rev[q])
				q = pi_rev[q - 1];
			if (virus_rev[p] == virus_rev[q])
				pi_rev[p] = ++q;
			else
				pi_rev[p] = 0;
		}
		for (int j = 1; j < n; ++j) {
			if (!kmp(virus, program[j]) && !kmp_rev(virus_rev, program[j])) {
				isVirus = false; break;
			}
		}
		if (isVirus) {
			printf("YES"); break;
		}
	}
	if (!isVirus)
		printf("NO");
	return 0;
}
