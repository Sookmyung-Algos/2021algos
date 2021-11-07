#include <iostream>
#include <string>
#define MAX 64
using namespace std;

int N;
int arr[MAX][MAX];

void check(int n, int y, int x){
        if (n == 1){ // base
        	cout << arr[y][x];
        	return;
        }

        bool zero = true, one = true;
        for (int i = y; i < y + n; i++){
        	for(int j=x; j<x+n; j++){
        		if(arr[i][j]) zero = false;
        		else one = false;
        	}
        }
               
        if (zero) cout << 0;
        else if(one) cout << 1;
        else{
        	 cout << "(";
        	 check(n / 2, y, x); //2사분면
        	 check(n / 2, y, x + n / 2); //1사분면
        	 check(n / 2, y + n / 2, x); //3사분면
        	 check(n / 2, y + n / 2, x + n / 2); //4사분면
        	 cout << ")";
        }
        return;
}

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    bool zero = true, one = true;
    for (int i = 0; i < N; i++){
    	string s; cin >> s;
    	for (int j = 0; j < N; j++)
    		arr[i][j] = s[j] - '0';
    }
    check(N, 0, 0);
    cout << "\n";
    return 0;
}
