#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int number,n;
    int a=0, b=0;
    int count=0;
    cin >> number;
    n=number;

    if(number == 0){
        cout << 1;
        return 0;
    }
    if(number<100){
        while(b != n){
            a = (number%10) + (number/10);
            b = (number%10)*10 + (a%10);
            number = b;
            count++;
        }
    
    cout << count;
    }
    return 0;
}
