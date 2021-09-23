#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

string s, t;
int n;
int mode = 0, change[2];


int main() {

   int check = 1;
   
   cin >> n;
   
   cin >> s >> t;
   
   cin >> change[0] >> change[1];
   
   for(int i = 0, j = 0;  j < n;){
       
       if (i == change[0] || i == change[1]) {
           i++;
           continue;
           
       }

       
      if(i < n && s[i] == t[j]){
         i++;
         j++;
         continue;
      }
      else{
         if(mode == 2){
            check = 0;
            break;
         }
         else if(mode == 0){
            if(t[j] == s[change[mode]]){
               mode = 1;
               j++;
            }
            else{
                
                if(t[j-1] == s[change[0]] && t[j] == s[change[1]]){
                    mode = 2;
                    j++;
                    
                    if(i > change[1]){
                        i -= 3;
                    }
                    else if(i > change[0]){
                        i -= 2;
                    }
                    else{
                        i--;
                    }

                }
                else{
                    check = 0;
                    break;
                }
                
               
            }
         }
         else if(mode == 1){
            if(t[j] == s[change[mode]]){
               mode = 2;
               j++;
            }
            else{
               check = 0;
               break;
            }
         }
      }
      
   }
   
   if(check == 1){
      cout << "YES";
   }
   else{
      cout << "NO";
   }
   
   return 0;
}
