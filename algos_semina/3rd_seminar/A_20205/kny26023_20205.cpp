#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, k, i, j;
	cin >> n >> k;
	int map[105][105];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			int tmp;
			cin >> tmp;
			for(int a=i*k; a<i*k+k; a++){
				for(int b=j*k; b<j*k+k; b++){
					map[a][b]= tmp;
				}
			}
		}
	}
	for(i=0; i<n*k; i++){
		for(j=0; j<n*k; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
