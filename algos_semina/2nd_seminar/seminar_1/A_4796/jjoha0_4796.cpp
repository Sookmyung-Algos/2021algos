#include <iostream>

using namespace std;

int main()
{
    int tc = 1;
    while (1)
    {
        int L, P, V;
        cin >> L >> P >> V;
    
        if (!L && !P && !V)
            break;
        
        int cnt = 0;
        cnt = (V / P) * L;
        V = V % P;
        cnt += V < L ? V : L;
        
        cout << "Case " << tc++ << ": " << cnt << '\n';
    }
    return 0;
}
