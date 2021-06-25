#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

char map[510][510];
vector<pair<int, int>> sheep_p;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
    
    int r, c;
    int check = 1;
    
    cin >> r >> c;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char a;
            
            cin >> a;
            
            map[i][j] = a;
            
            if(a == 'S'){
                sheep_p.push_back({i, j});
            }
        }
    }
    
    for(int i = 0; i < sheep_p.size(); i++ ){
        for(int j = 0; j < 4; j++){
            int xx = sheep_p[i].first + dx[j];
            int yy = sheep_p[i].second + dy[j];
            
            if(xx >= 0 && yy  >= 0 && xx < r && yy < c){
                if(map[xx][yy] == 'W'){
                    check = 0;
                }
            }
        }
    }
    
    if(check == 0){
        cout << "0\n";
    }else{
        cout << "1\n";
        for(int i =0; i < r; i++){
            for(int j =0; j < c; j++){
                if(map[i][j] == '.'){
                    cout << 'D';
                }else{
                    cout << map[i][j];
                }
            }
            cout << "\n";
        }
    }
    
}
