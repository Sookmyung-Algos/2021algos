#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int L,P,V;
    int cnt=1;
    while (1){
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V==0) break;
        
        int a,day=0;
        if (V%P > L) a=L;
        else a = V%P;
        
        day = L*(V/P) + a;
        cout << "Case " << cnt << ": " << day << endl;
        cnt++;
    }
    return 0;
}
