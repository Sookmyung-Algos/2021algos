#include <iostream>
#define MAX 2190
using namespace std;

int N;
int graph[MAX][MAX]={0,};
int cnt[4]={0,};

void divided(int x,int y,int num){
    bool flag=true;
    int temp = graph[x][y];
    
    // 현재 위치와 graph[i][j]의 값이 다르면 반복문 나오기
    for (int i=x;i<x+num;i++){
        for (int j=y;j<y+num;j++){
            if (temp!=graph[i][j]) {
                flag=false;
                break;
            }
        }
    }
    
    // 위치에 맞춰 종이 자르기
    if (!flag) {
        for (int i=x;i<x+num;i+=num/3){
            for (int j=y;j<y+num;j+=num/3){
                divided(i,j,num/3);
            }
        }
    } else {
        cnt[temp+1]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> graph[i][j];
        }
    }
    divided(0,0,N);
    
    for (int i=0;i<3;i++){
        cout << cnt[i] << '\n';
    }
}
