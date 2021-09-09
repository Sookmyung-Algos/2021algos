#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>

using namespace std;

int n;
long long counter = 0;

map<int, pair<pair<int, int>, long long>> tree;

void insert(int x, map<int, pair<pair<int, int>, long long>>:: iterator it){
    int max = -1, min = -1;
    
    if(it -> first < x){
        min = it -> first;
        max = -1;
    }
    else{
        map<int, pair<pair<int, int>, long long>>:: iterator lower = tree.lower_bound(x);
        
        if(lower == tree.begin()){
            min  = -1;
            max = lower -> first;
        }
        else{
            max = lower -> first;
            lower--;
            min = lower -> first;
        }
    }
    
    if(min != 0 && max != 0){
        if(tree[max].first.first == 0){
            tree[max].first.first = x;
            tree[x].second = tree[max].second + 1;
        }
        else{
            tree[min].first.second = x;
            tree[x].second = tree[min].second + 1;
        }
    }
    else if(min == -1 && max != -1){
        tree[min].first.first = x;
        tree[x].second = tree[max].second + 1;
    }
    else if(min != -1 && max == -1){
        tree[min].first.second = x;
        tree[x].second = tree[min].second + 1;
    }
    
    counter += tree[x].second;
    cout << counter << "\n";
    
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i =0; i< n; i++){
        int a;
        
        cin >> a;
        
        if(i == 0){
            tree[a].second = 0;
            cout << "0\n";
            continue;
        }
        
        auto it = tree.end();
        it--;
        
        
        insert(a, it);
        
    }
    
}
