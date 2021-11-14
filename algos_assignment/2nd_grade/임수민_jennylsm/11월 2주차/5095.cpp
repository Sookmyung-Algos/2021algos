#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Matrix {
	vector<vector<int>> v; const int sz, MOD;
	Matrix(int sz, int MOD) : v(sz, vector<int>(sz)), sz(sz), MOD(MOD) {}
	void UnitMatrix() { for (int i = 0; i < sz; i++) v[i][i] = 1; }
	void Multiply(Matrix M) {
		Matrix ret(sz, MOD);
		for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) for (int k = 0; k < sz; k++) {
			ret.v[i][j] += 1LL * v[i][k] * M.v[k][j] % MOD;
			if (ret.v[i][j] >= MOD) ret.v[i][j] -= MOD;
		}
		v = ret.v;
	}
	Matrix Pow(int n) {
		Matrix ret(sz, MOD); ret.UnitMatrix();
		for (; n; n >>= 1) {
			if (n & 1) ret.Multiply(*this);
			Multiply(*this);
		}
		return ret;
	}
	void Print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) cout << v[i][j] << ' ';
			cout << '\n';
		}
	}
};

int main() {
	fastio;
	for (int n, m, MOD; cin >> n >> MOD >> m && n;) {
		Matrix M(n, MOD);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> M.v[i][j];
		M.Pow(m).Print(); cout << '\n';
	}
}
