#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

int del_cnt = 0;

int plug_used[110];
int order[110];

int arr[110];
queue<int> q[110];

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

int main(){
    
    int n, k;
    int current = 1;
    int overlap_cnt = 0;
    
    cin >> n >> k;
    
    for(int i = 1; i<= k; i++){
        int a;
        
        cin >> a;
        
        order[i] = a;
        
        q[a].push(i);
    }
    
    //cout << pq2.top().first << " " << pq2.top().second << "\n";
    
    //cout << q[2].front() << "\n";
    //q[2].pop();
    //cout << q[2].front() << "\n";
    
    while(pq.size() - overlap_cnt < n){
        if(current > k){
            break;
        }
        if(plug_used[order[current]] == 0){
            plug_used[order[current]] = 1;
            q[order[current]].pop();
            if(!q[order[current]].empty()){
                pq.push({q[order[current]].front(), order[current]});
            }
            else{
                pq.push({500010, order[current]});
            }
        }else{
            q[order[current]].pop();
            
            if(!q[order[current]].empty()){
                pq.push({q[order[current]].front(), order[current]});
                overlap_cnt++;
            }
            else{
                pq.push({500010, order[current]});
                overlap_cnt++;
            }
        }
        current++;
    }
    
    /*
    for(int i = 0; i<n; i++){
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }
    */
    
    while(current <= k){
        //cout << "yo: " << order[current] << "\n";
        if(plug_used[order[current]] == 0){
            //cout << "here\n";
            plug_used[order[current]] = 1;
            plug_used[pq.top().second] = 0;
            //cout << pq.top().first << " " << pq.top().second << "\n";
            pq.pop();
            
            q[order[current]].pop();
            
            if(!q[order[current]].empty()){
                pq.push({q[order[current]].front(), order[current]});
            }
            else{
                pq.push({500010, order[current]});
            }
            del_cnt++;
        }
        else{
            q[order[current]].pop();
            
            if(!q[order[current]].empty()){
                pq.push({q[order[current]].front(), order[current]});
            }
            else{
                pq.push({500010, order[current]});
            }
        }
        current++;
    }
    
    cout << del_cnt;

}
