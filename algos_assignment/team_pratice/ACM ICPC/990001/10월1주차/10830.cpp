#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long B;
long long matrix[6][6];
long long result[6][6];
long long temp[6][6];

void multiply(long long m1[6][6],long long m2[6][6]){
    // 행렬 제곱
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            temp[j][i]=0;
            for (int k=0;k<N;k++){
                temp[j][i] += (m1[k][i]*m2[j][k]);
            }
            temp[j][i]= temp[j][i]%1000;
        }
    }
    // 행렬 copy
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            m1[j][i] = temp[j][i];
        }
    }
}
void print(long long arr[6][6]){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // N,B 입력받기
    cin >> N >> B;
    
    // 행렬 입력받기
    for (int i=0;i<N;i++){
        result[i][i]=1; // 단위행렬로 초기화시켜놓기
        for (int j=0;j<N;j++){
            cin >> matrix[i][j];
        }
    }
    
    /* 행렬 계산하기 */
    // B--로 while문 돌리면 시간초과뜸
    while (B>0){
        if (B%2==1){
            multiply(result,matrix);
        }
        multiply(matrix,matrix);
        B = B/2;
    }
    print(result);
}
