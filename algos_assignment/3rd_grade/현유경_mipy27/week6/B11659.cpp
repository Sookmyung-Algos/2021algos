#include <iostream>
#define NUMBER 100001
using namespace std;

int n, m;
int a[NUMBER]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    
    cin >> n >> m;
    
    int num;
    for (int i=0;i<n;i++){
        cin >> num;
        a[i+1]=a[i]+num; //입력받은 숫자 누적해서 합 구하기 
    }
    
    for (int i=0;i<m;i++){
        int start,end;
        cin >> start >> end;
        cout << a[end]-a[start-1] << '\n'; // 구간 합 구하기
    }
    return 0;
}
