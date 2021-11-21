#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n;
int matrix[51][51];
int score[51];

void Floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            matrix[i][j] = (i==j) ? 0:INF;
        }
    }
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == -1) break;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    Floyd();
    int hoobo = -1;
    for(int i = 1; i <= n; i++){
        int max = 0;
        for(int j = 1; j <= n; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
        score[i] = max;
        if(hoobo > max || hoobo == -1){
            hoobo = max;
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(score[i] == hoobo){
            count++;
        }
    }
    cout << hoobo << " " << count << '\n';
    for(int i = 1; i <= n; i++){
        if(score[i] == hoobo){
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}
