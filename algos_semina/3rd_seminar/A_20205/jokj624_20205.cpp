//AC
//BOJ 20205 교수님 그림이 깨지는데요?
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int pixel[12][12];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K, px;
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> pixel[i][j];
        } 
    }
    int x = 0, y = 0;
    for(int i=0; i<N*K; i++) {
        if(i%K == 0 && i != 0)    x++;
        for(int j=0; j<N*K; j+=K) {
            for(int k=0; k<K; k++) {
                cout << pixel[x][y] << " ";
            }
            y++;
        }
        y=0;
        cout << "\n";
    }

    return 0;
}