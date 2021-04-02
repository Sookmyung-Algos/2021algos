#include<iostream>
//#include<vector>

using namespace std;

int main() {

	int testcase;

	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int n, m;
		//vector<int>plane_route[10010];

		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int a, b;

			cin >> a >> b;

			//plane_route[a].push_back(b);
			//plane_route[b].push_back(a);

		}

		cout << n - 1 << "\n";

		/*
		// 짧게 풀자면...?
		// 비행기 스케쥴이 항상 연결 그래프를 이룬다...는 조건
		cout << n - 1 << "\n";
		*/

	}

}
