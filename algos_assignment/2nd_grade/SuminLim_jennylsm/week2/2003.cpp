#include <iostream>
using namespace std;

const int MAX = 10000;
int arr[MAX];

int main(void){
int N, M;
cin >> N >> M;  //첫째줄에 M과 N을 입력받기
for (int i = 0; i < N; i++)  cin >> arr[i];   //반복문으로 배열 입력받기
int i = 0, j = 0; 
int sum = arr[0];
int result = 0;    //투 포인터
while (i <= j && j < N){
        if (sum < M)    sum += arr[++j];
        else if (sum == M){
            result++;  //sum이 M과 같은 경우 result에 1더해준다
            sum += arr[++j];  
        }
        else if (sum > M){
            sum -= arr[i++];     
            if (i > j && i < N){     //i가 j를 역전하면 i에서부터 다시 시작
                j = i;
                sum = arr[i];
            }
        }
    }
cout << result << "\n";
return 0;
}
