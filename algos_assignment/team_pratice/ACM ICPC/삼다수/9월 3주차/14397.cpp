#include <iostream>
#include <vector>

//단위 정육각형 이루어져 있는 지도가 주어졌을 때, 해변의 길이를 구하는 프로그램
//해변은 정육각형의 변 중에서 한 쪽은 물인데, 한 쪽은 땅인 곳을 의미

using namespace std;

int sol(int n, int m, vector<vector<int>> maps){
    int cnt = 0;

    int posX[] = {-1, -1, 0, 0, 1, 1};
    int posY_odd[] = {0, 1, -1, 1, 0, 1}; // 세로가 홀수번째일 때 
    int posY_even[] = {-1, 0, -1, 1, -1, 0}; // 세로가 짝수번째일 때 

    // 노드중에 땅일 때에만 주변 노드 확인
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){

            if(maps[x][y]) continue; // 바다->넘겨줌

            // 주변 노드 확인
            for(int i = 0; i < 6; i++){
                int tempX = x + posX[i], tempY;
                if(x % 2 == 0) tempY = y + posY_even[i];
                else tempY = y + posY_odd[i];

                // 범위에 해당하는것만 카운트
                if(-1 < tempX && tempX < n && -1 < tempY && tempY < m){
                    if(maps[tempX][tempY]) cnt ++;
                }
            } // 주변 노드 확인 끝
        }
    }

    return cnt;
}

int main(){

    int n, m; cin >> n >> m;
    vector<vector<int>> maps(n);

    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        for(auto now: temp){
            if(now == '.') maps[i].push_back(1);
            else maps[i].push_back(0);
        }
    }

    cout << sol(n, m, maps) << endl;

    return 0;
}
