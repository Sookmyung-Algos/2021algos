#include<iostream>  
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
   cin.tie(0); cout.tie(0);
   ios_base::sync_with_stdio(false);

   vector <int> v(500010);
   int n,a;

   cin >> n;
   for (int i=0; i < n; i++) {
      cin >> a;
      v[a] += 1;
   }
   cout << *max_element(v.begin(), v.end());
}
