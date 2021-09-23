//two pointer
#include <iostream>
using namespace std;

int main() {
    int arr[10001];
    int n, m;
    cin >> n >> m; //n m 순으로 값 입력받기 (1)

    for (int i = 0; i < n; i++) {
        cin >> arr[i];; //arr에 입력받은 수 저장 (2)
    }
    int s = 0, e = 0; //시작과 끝 (s <= e)
    int cnt = 0, sum = 0; 

    while (1) { //s < n 인 동안 반복문 실행
        if (sum >= m) sum -= arr[s++]; //s가 커지면 sum에 빼기
        else if (e == n) break; //e와 n이 같으면 빠져나가기
        else sum += arr[e++]; //e가 커지면 sum에 더하기
        if (sum == m) cnt++; //sum이 m과 같아지면 cnt 올리기
    }
    cout << cnt << '\n';
    return 0;
}
