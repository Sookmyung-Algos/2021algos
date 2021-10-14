#include <iostream>
using namespace std;
long long Parray[101] = {0,1,1,};
long long P(int N)
{
    if(N < 3)
        return Parray[N];
    else if(Parray[N] == 0)
        Parray[N] = P(N-2) + P(N-3);
    return Parray[N];
}
int main() {
    int T;
    int N;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        cout << P(N) << '\n';
    }
}
