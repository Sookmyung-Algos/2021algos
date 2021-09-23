#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
struct coordinate {
	int x;
	int y;
} c[MAX];
bool f(coordinate a, coordinate b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i].x >> c[i].y;
	sort(c, c + n, f);
	for (int i = 0; i < n; i++)
		cout << c[i].x << ' ' << c[i].y << '\n';
	return 0;
}
