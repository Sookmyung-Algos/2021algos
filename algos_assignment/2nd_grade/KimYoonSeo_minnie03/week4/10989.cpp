#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);

    int cnt[10001] = { 0, };//배열 cnt에 숫자 index 별로 입력된 횟수 저장

    for (int i = 0; i < n; i++){ //n개의 숫자를 입력받음
        int a;
        scanf("%d", &a);
        cnt[a]++; //입력받은 숫자의 index에 입력받은 횟수 저장
    }

    for (int i = 0; i < 10001; i++) //입력한 값 중 가장 큰 숫자까지
        for (int j = 0; j < cnt[i]; j++) //각 숫자가 입력된 횟수만큼 
            printf("%d\n", i); //출력
}
