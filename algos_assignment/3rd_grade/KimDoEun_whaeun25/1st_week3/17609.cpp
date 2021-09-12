#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n, back, check = 1;
    
    cin >> n;
    
    for(int i =0; i<n;i++){
        check = 1;
        string s;
        
        cin >> s;
        
        back = s.size() - 1;
        
        for(int i = 0, j = back; j > i; i++, j--){
            
            if(s[i] == s[j]){
                continue;
            }
            else{
                check = 0;
            }
                
            if (s[i + 1] != s[j] && s[i] != s[j - 1]) {
                check = 2;
                break;
            }
            for(int k =0; k <2; k++){
                check = 0;
                int start = i, end = j;
                
                if(k == 0){
                    start++;
                }else{
                    end--;
                }
                
                for(int a = start, b = end; a<b; a++, b--){
                    if(s[a] != s[b]){
                        check = 2;
                        break;
                    }
                }
                if(check == 0){
                    break;
                }
            }
            break;
        }
        
        if(check == 1){
            cout << 0 << "\n";
        }
        else if(check ==2){
            cout << 2 << "\n";
        }
        else{
            cout << 1 << "\n";
        }
    }
    
}
