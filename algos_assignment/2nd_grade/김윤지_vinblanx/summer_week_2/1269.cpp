#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int aSize, bSize;
    map<int, int> a, b;
    
    cin >> aSize >> bSize;
    
    for(int i = 0; i < aSize; i++){
        int temp;
        cin >> temp;
        a[temp] = temp;
    }
    
    for(int i = 0; i < bSize; i++){
        int temp;
        cin >> temp;
        b[temp] = temp;
    }
    
    int sum = 0;
    for(map<int, int>::iterator it = a.begin(); it != a.end(); it++){
        if(!b[it->first])
            sum++;
    }
  
    for(map<int, int>::iterator it = b.begin(); it != b.end(); it++){
        if(!a[it->first])
            sum++;
    }
    
    cout << sum << '\n';
    
    return 0;
}
