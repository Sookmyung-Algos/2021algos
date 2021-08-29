#include <iostream>

using namespace std;

bool extended[101][101];

int main()
{
    int N, K;
    
    cin >> N >> K;
    
    for (int i =0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool origin_pixel;
            cin >> origin_pixel;
            for (int m = i*K; m < i*K+K; m++)
            {
                for (int n= j*K; n < j*K + K; n++)
                    extended[m][n] = origin_pixel;
            }
        }
    }
    for (int i=0; i < N*K;i++)
    {
        for (int j = 0; j < N*K; j++)
            cout << extended[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
