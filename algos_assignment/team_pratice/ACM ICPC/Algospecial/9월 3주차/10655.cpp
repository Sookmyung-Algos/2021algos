#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

#define MAX 1005

using namespace std;

int n;
int answer = 0;

vector<pair<int, int>> run;

int distance(int x1, int x2, int y1, int y2){
    
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
    int x = 0, y = 0;
    int sum = 0;
    
    cin >> n;
    
    for(int i = 0; i< n; i++){
        int a, b;
        
        cin >> a >> b;
        
        run.push_back({a, b});
        
        if(i == 0){
            x = a;
            y = b;
        }
        else{
            
            sum += distance(x, a, y, b);
            
            x = a;
            y = b;
        }
        
    }
    
    int pass = 0;
    
    for(int i = 1; i < n-1; i++){
        int x1 = run[i-1].first;
        int y1 = run[i-1].second;
        
        int x2 = run[i].first;
        int y2 = run[i].second;
        
        int x3 = run[i+1].first;
        int y3 = run[i+1].second;
        
        int w1 = distance(x1, x2, y1, y2) + distance(x2, x3, y2, y3);
        int w2 = distance(x1, x3, y1, y3);
        
        pass = (pass > w1 - w2)? pass : w1 - w2;
    }
    
    answer = sum - pass;
    
    cout << answer;
}
