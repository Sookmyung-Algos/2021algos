#include <iostream>

using namespace std;

int count_five(long long int x) {
   if( x == 0 ) return 0;
   return (x % 10 == 5) + count_five(x/10);
}

int main( void ) {
    long long int n;
    int k;
    scanf( "%lld %d", &n, &k);
    n++; // n보다 큰 수를 찾으라고 했으니..
    
    long long int pow = 1;
    while (1) {
        if (count_five(n) >= k) break;
        while((n/pow) % 10 == 5) pow *= 10;
        n += pow;
    }
    printf("%lld\n", n);

    return 0;
}
