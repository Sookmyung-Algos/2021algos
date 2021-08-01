#include <iostream>
using namespace std;
int n,k;
int arr[110][110];
int main() {
	int num;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> num;
			for(int a = i*k;a<i*k+k;a++){
				for(int b = j*k;b<j*k+k;b++){
					arr[a][b] = num;
				}
			}
		}
	}
	for(int i=0;i<n*k;i++){
		for(int j=0;j<n*k;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
