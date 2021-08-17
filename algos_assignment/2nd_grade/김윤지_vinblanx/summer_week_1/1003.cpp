#include <iostream>

using namespace std;

long long fiboarr[50] = {0,1,};
long long fibo(int N)
{
    if(N == 0 || N == 1)
        return fiboarr[N];
    else if(fiboarr[N] == 0)
        fiboarr[N] = fibo(N-1) + fibo(N-2);
    return fiboarr[N];
}

int main() {
    int T;
    cin >> T;
    int tmp;
    for(int i = 0; i < T; i++)
    {
        cin >> tmp;
        if(tmp == 0)
            cout << "1 0" << '\n';
        else
            cout << fibo(tmp-1) << ' ' << fibo(tmp) << '\n';
    }
    return 0;
}
