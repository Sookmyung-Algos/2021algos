#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> project;
int arr[1001] = {0, };

int main(){
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i<n; i++){
        int day, score;
        
        cin >> day >> score;
        
        project.push_back(make_pair(score, day));
    }
    
    sort(project.begin(), project.end());
    
    for(int i = (int)project.size()-1; i>=0; i--){
        int end_day = project[i].second;
        while(end_day > 0){
            if(arr[end_day] == 0){
                arr[end_day] = project[i].first;
                break;
            }
            else{
                end_day--;
            }
        }
    }
    
    int sum =0;
    
    for(int i =1; i<=1000; i++){
        sum += arr[i];
    }
    
    cout << sum;
    
}
