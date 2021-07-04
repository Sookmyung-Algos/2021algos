#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int A, B;
    cin >> A >> B;
    
    int C;
    cin >> C;
    
    int D[100];
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    sort(D, D + N, greater<int>());
    
    int cal = C;
    int price = A;
  
    for (int i = 0; i < N; i++)
    {
        if (C/A < D[i] / B)
        {
            C += D[i];
            A += B;
        }
    }
    cout << C/A;
    return 0;
}
