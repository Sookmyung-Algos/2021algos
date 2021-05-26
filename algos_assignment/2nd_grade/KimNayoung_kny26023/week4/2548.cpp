#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    vector <int> v;
    int n, answer;
    
    scanf("%d", &n);
    v.resize(n);
  //v를 n 사이즈로 resize해준다.
    
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    sort(v.begin(), v.end());
  //v.begin()과 v.end()까지를 넣고 sort해준다.
    
    if (n % 2)
        answer = v[n/2];
  //n%2가 1이면 answer= v[n/2]이다.
    else
    {
        if (v[n/2] > v[n/2-1])
            answer = v[n/2-1];
      //n%2가 0이고 v[n/2]가 v[n/2-1]보다 크면 answer= v[n/2-1]이다.
        else
            answer = v[n/2];
      //n%2가 0이고 v[n/2]가 v[n/2-1]랑 같으면 answer= v[n/2]이다.
    }
    
    printf("%d", answer);
    return 0;
}
