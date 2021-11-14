#include <iostream>

using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size){
	if (y == r && x == c){
		cout << ans << '\n';
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x){
		Z(y, x, size / 2);
		Z(y, x + size / 2, size / 2);
		Z(y + size / 2, x, size / 2);
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else ans+= size * size;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> c;
	Z(0, 0, (1 << n));
	return 0;
}
