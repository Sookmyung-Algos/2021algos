#include <iostream>
#define MAX 501
using namespace std;

int R, C;
char arr[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int check(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (ny>=0 && ny<R && nx>=0 && nx<C) {
		    if (arr[ny][nx] == 'W') 
			    return 1; // 울타리 불가능
		}
	}
	return 0;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	for (int i = 0; i < R; i++) { // y좌표
		for (int j = 0; j < C; j++) { // x좌표
			if (arr[i][j] == 'S') {
				int avail = check(i, j);
				if (avail == 1) {
					cout << "0\n";					
					return 0;
				}
			}
		}
	}

	cout << "1\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++){
            if (arr[i][j]=='.')
                cout<<'D';
            else
			    cout << arr[i][j];
        }
		cout << "\n";
	}

	return 0;
}
