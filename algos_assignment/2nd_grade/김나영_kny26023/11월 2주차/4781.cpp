#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
#define MAX 5001

int n, c; 
double m, p;
pair<int, int> candy[MAX];
int cache[10001];


int maxc(int cash){
        int &result= cache[cash];
        if (result!= -1)
            return result;
        result= 0;
        for (int i=0; i<n; i++){
            if (cash - candy[i].second >= 0)
                result = max(result, candy[i].first+ maxc(cash- candy[i].second));

        }
        return result;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true){
        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        if (n == 0 && m == 0.00)
            break;
        for (int i = 0; i < n; i++){
            cin >> c >> p;
            candy[i] = make_pair(c, (int)(p * 100 + 0.5));
        }
        cout << maxc((int)(m * 100 + 0.5)) << "\n";

        }
        return 0;
}
