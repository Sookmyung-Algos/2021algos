#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define MAX 310

using namespace std;

int mapp[MAX][MAX];
int answer = 0;

int n, m;

int check(int y, int x){
    int cnt = 0;

    //일렬 가로
    int sum = 0;
    for(int i = 0; i < 10; i++){

        if(x+i >= m){
            break;
        }
        sum += mapp[y][x+i];

        if(sum == 10){
            cnt++;
            //cout << "1 \n";
        }
        if(sum >= 10){
            break;
        }
    }

    //일렬 세로
    sum = 0;

    for (int i = 0; i < 10; i++){
        if(y+i >= n){
            break;
        }

        sum += mapp[y+i][x];

        if (sum == 10){
            if(i == 0){
                break;
            }
            //cout << "2 \n";
            cnt++;
        }
        if (sum >= 10){
            break;
        }
    }

    //2 사각형 2*2 2*3 2*4 2*5 

    sum = 0;

    for(int i = 0; i<5; i++){
        sum += mapp[y + i][x];
        sum += mapp[y + i][x+1];

        if(y+i >= n || x+1 >= m){
            break;
        }

        if (sum == 10){
            if(i == 0){
                break;
            }
            //cout << "3 \n";
            cnt++;
        }
        if (sum >= 10){
            break;
        }
    }

    sum = 0;

    for (int i = 0; i < 5; i++){
        sum += mapp[y][x + i];
        sum += mapp[y + 1][x + i];

        if(y + 1 >= n || x + i >= m){
            break;
        }

        if (sum == 10){
            if (i == 0 || i == 1){
                break;
            }

            //cout << "4 \n";
            //cout << "y: " << y << "x: " << x <<"\n";
            cnt++;
        }
        if (sum >= 10){
            break;
        }
    }

    // 정사각형 3*3
    sum = 0;
    int ok = 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(y + i >= n || x + j >= m){
                ok = 0;
            }
            sum += mapp[y+i][x+j];
        }
    }

    if(ok == 0){
        return cnt;
    }

    if(sum == 10){
        cnt++;

        //cout << "5 \n";
    }

    return cnt;
}


int main(){

    cin >> n >> m;

    for(int i = 0; i< n; i++){
        for(int j =  0; j < m; j++){
            int a;

            cin >> a;

            mapp[i][j] = a;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            answer += check(i, j);
        }
    }

    cout << answer;

}
