#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <iterator>

using namespace std;

long long Answer;
long long n, m;


int main(int argc, char** argv)
{
    int T, test_case;
    

    cin >> T;
    
    for(test_case = 0; test_case  < T; test_case++){
        
        Answer = 0;
        long long sum = 0;
        
        cin >>  n >> m;
        
        set<long long> s;
        
        s.insert(0);
        
        for(int i = 0; i <n; i++){
            long long a;
            
            cin >> a;
            
            sum += a;
            
            s.insert(sum);
            
            set<long long>::iterator it = s.lower_bound(sum - m);
            
            if(it != s.end()){
                Answer = max(Answer, sum - *it);
            }
            
        }
        
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;}
