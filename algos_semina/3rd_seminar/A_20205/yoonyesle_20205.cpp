#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int map[11][11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    
    cin >> n >> k;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int g = 0; g < k; g++){
            for(int j = 0; j < n; j++){
                for(int l = 0; l < k; l++){
                    cout << map[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
}
