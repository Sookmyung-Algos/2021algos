#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> cost;

vector<int> connect;

double answer = 0;

double distance(pair<double, double> cord1, pair<double, double> cord2){
    
    double x1 = cord1.first;
    double y1 = cord1.second;
    
    double x2 = cord2.first;
    double y2 = cord2.second;
    
    return sqrt(pow(x2-x1, 2)+ pow(y2-y1, 2));
}

int find(int a){
    if(a == connect[a]){
        return a;
    }
    
    connect[a] = find(connect[a]);
    
    return connect[a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i <n; i++){
        double x, y;
        
        cin >> x >> y;
        
        star.push_back({x, y});
    }
    
    for(int i = 0; i < star.size(); i++){
        for(int j = i+1; j < star.size(); j++){
            double w = distance(star[i], star[j]);
            
            cost.push_back({w, {i, j}});
        }
    }
    
    sort(cost.begin(), cost.end());
    
    for(int i = 0; i <= n; i++){
        connect.push_back(i);
    }
    
    //kruskal algorithm
    for(int i = 0; i < cost.size(); i++){
        int x = cost[i].second.first;
        int y = cost[i].second.second;
        
        double w = cost[i].first;
        
        int a = find(x);
        int b = find(y);
        
        if(a != b){
            connect[a] = b;
            answer += w;
        }
    }
    
    cout.precision(3);
    cout << answer;
    
}

