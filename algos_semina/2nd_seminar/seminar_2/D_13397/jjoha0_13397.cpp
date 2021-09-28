#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int A[20001];
int B[20001];

bool desc(int a, int b)
{
    return a > b;
}
int main()
{
    int T, m, n;
    cin >> T;
    
    for (int i = 0; i < T; i++){
        int cnt = 0;
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        cin >> m >> n;
        for (int j = 0; j < m; j++)
            cin >> A[j];
            
        for (int k=0; k < n; k++)
            cin >> B[k];
            
        sort(A, A + n, desc);
	    sort(B, B + n, desc);

        for(int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(A[i] > B[j])
                {
                    cnt += (n - j);
                    break;
                }                    
            }
        }
        cout << cnt << "\n";
    }
   
    return 0;
}
