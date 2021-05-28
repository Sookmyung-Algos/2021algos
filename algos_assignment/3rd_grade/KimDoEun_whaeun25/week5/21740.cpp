#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<pair<int, int>> dodo;

int rotate_number(int num){
    switch(num){
        case 6:
            return 9;
            break;
        case 9:
            return 6;
            break;
        default:
            return num;
    }
}

int int_size(int num){
    int count = 0;
    for(count = 0; num > 0; count++){
        num /= 10;
    }
    return count;
}

int reverse_num(int num){
    int result = 0;
    
    //cout << "\nsize): " << int_size(num) << "\n";
    int num_size = int_size(num);
    for(int i =0; i < num_size; i++){
        result = result * 10 + rotate_number(num % 10);
        num /= 10;
    }
    
    return result;
}

bool cmp(const pair<int, int> & a, const pair<int, int> & b){
    long long sum1 = 0, sum2 = 0;
    
    sum1 = a.first * pow(10, int_size(b.second)) + b.first;
    sum2 = b.first * pow(10, int_size(a.second)) + a.first;
    
    //cout << "a.first: " << a.first << " b.first" << b.first << "\n";
    //cout << "sum1: " << sum1 << " sum2: " << sum2 << "\n";
    
    return sum1 < sum2;
}

int main(){
    int n, max_num = 0;
    int max_num_origin = 0;
    
    cin >> n;
    
    for(int i =0; i<n; i++){
        int a, reverse_a;
        
        cin >> a;
        
        reverse_a = reverse_num(a);
        //cout << "reverse_a " << reverse_a << "\n";
        
        if((max_num < reverse_a && int_size(max_num_origin) <= int_size(a))  || int_size(max_num_origin) < int_size(a)){
            //cout <<"max_num: " <<a << "\n";
            max_num = reverse_a;
            max_num_origin = a;
        }
        
        dodo.push_back(make_pair(reverse_a, a));
    }
    //cout << "max_num : " << max_num << "\n";
    
    dodo.push_back(make_pair(max_num, max_num_origin));
    
    sort(dodo.begin(), dodo.end(), cmp);
    
    for(int i =0; i<=n; i++){
        cout << dodo[i].second;
    }
}

