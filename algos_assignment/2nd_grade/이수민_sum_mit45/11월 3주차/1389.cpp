// S1_1389 케빈 베이컨의 6단계 법칙

#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX];

void floyd(){ // 플로이드 알고리즘
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (i == j)
                    continue;
                else if (arr[i][k] && arr[k][j]){
                    if (arr[i][j] == 0)
                        arr[i][j] = arr[i][k] + arr[k][j];
                    else //베이컨의 수가 적어야하므로
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int n1, n2;
        cin >> n1 >> n2;
        arr[n1][n2] =arr[n2][n1] = 1;
    }

    floyd();
    int result = INF;
    int person;
    for (int i = 1; i <= N; i++){
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += arr[i][j];
        if (result > sum){ //최소 베이컨 수일 때
            result = sum;
            person = i; //해당 사람을 저장
        }
    }
        cout << person << endl;
        return 0;
}
