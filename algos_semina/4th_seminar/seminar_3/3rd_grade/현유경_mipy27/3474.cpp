/*
 📌 0의 개수를 어떻게 구할지
 // 오른쪽 끝의 0의 개수를 구하면 되니까 10의 개수를 구하면 됨
 // 10은 2와 5의 곱이기 때문에 2와 5의 개수 중 작은 값을 구하면 그게 0의 개수임
 // 5는 항상 2보다 적은 수가 나오기 때문에 5의 개수를 구하면 됨
 
 📌 팩토리얼을 어떻게 계산할지
 // 팩토리얼 직접 구하기x
 // n/m를 하면 n!에서 m를 포함하는 개수가 나옴
 // n의 2,3,.. 제곱수로 나눌 수 있게 증감식 작성
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int T,N;
    cin >> T;
    
    while (T--){
        cin >> N;
        
        long long five=0;
        for (int i=5;i<=N;i*=5){
            five += N/i;
        }
        cout << five << '\n';
    }
    return 0;
}
