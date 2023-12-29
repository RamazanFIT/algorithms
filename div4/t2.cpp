#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    freopen("nenokku_easy.in", "r", stdin);
    freopen("nenokku_easy.out", "w", stdout);
    string massive = "";
    vector<bool> ans;
    for(int i = 0; i <= 30; i++){
      
        string s;
        
        
        
        getline(cin, s);

        if(s.size() == 0) break;
        
     
        if(s[0] == 'A'){
 
            for(int i = 2; i < s.size(); i++){
                if(s[i] == ' '){
                    massive += ' ';
                    continue;
                }
                if((s[i] >= 'a' and s[i] <= 'z')){
                    massive += s[i];
                } else{
                    massive += tolower(s[i]);
                }
            }
        } else{
            if(massive.find(s) == -1){
                // cout << "NO" << ENDL;
                ans.push_back(0);
            } else{
                // cout << "YES" << ENDL;
                ans.push_back(1);
            }
        }
    }
    for(auto it : ans){
        if(!it){
                cout << "NO" << ENDL;
                
            } else{
                cout << "YES" << ENDL;
         
            }
    }


    endd
}