#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>

using namespace std;
char map[3073][6145];
void star(int n, int dx, int dy){
	if(n==3){
		map[dy][dx] = '*';
		map[dy+1][dx] = ' ';
		map[dy+1][dx-1] = '*';
		map[dy+1][dx+1] = '*';
		map[dy+2][dx-2] = '*';
		map[dy+2][dx-1] = '*';
		map[dy+2][dx] = '*';
		map[dy+2][dx+1] = '*';
		map[dy+2][dx+2] = '*';
		return;
	}
	star(n/2,dx-n/2,dy+n/2);
	star(n/2,dx+n/2,dy+n/2);
	star(n/2,dx,dy);
}
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=2*n; j++){
			map[i][j]=' ';
		}
	}
	star(n,n,1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=2*n; j++){
			cout<<map[i][j];
		}
		cout<<"\n";
	}
}
