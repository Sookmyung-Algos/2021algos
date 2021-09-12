#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int small_alpha[26];
int big_alpha[26];
int space_use = 0;

int main(){
    
    int n, small_alpha_num[26] = {0, }, big_alpha_num[26] = {0, }, space_exist = 0;
    int check = 1;
    
    cin >>n;
    
    for(int i =0; i<n; i++){
        int a;
        
        cin >> a;
        
        if(a == 0){
            space_exist = 1;
        }
        else if(a >= 1 && a <= 26){
            big_alpha_num[a-1]++;
        }
        else if(a >= 27 && a <= 52){
            small_alpha_num[a-27]++;
        }
    }
    
    string s;
    
    getchar();
    getline(cin, s);
    
    for(int i =0; i<n; i++){
        if(s[i] == ' '){
            space_use = 1;
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            //cout << s[i] - 'a' << "\n";
            small_alpha[s[i] - 'a']++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            //cout << s[i] - 'A' << "\n";
            big_alpha[s[i] - 'A']++;
        }
    }
    
    if(space_use == 1){
        if(space_exist == 0){
            check = 0;
        }
    }
    
    for(int i =0; i<26;i++){
        
        //cout << "i: " << small_alpha_num[i] << "\n";
        if(small_alpha_num[i] != small_alpha[i]){
            //cout << small_alpha_num[i] << " " << small_alpha[i] << "\n";
            check = 0;
        }
        if(big_alpha_num[i] != big_alpha[i]){
            check = 0;
        }
    }
    
    if(check){
        cout << "y";
    }
    else{
        cout << "n";
    }
    //cout << s;
    
    
}
