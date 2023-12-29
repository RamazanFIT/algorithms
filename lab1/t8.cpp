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
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    string s;
    cin>>n>>s;
    int cnt_k = 0;
    int cnt_s = 0;
    int ost_k = 0;
    int ost_s = 0;
    int p_s = 0;
    int p_k = 0;
    queue<int> q;
    for(int i = 0; i < s.size(); i++){
        q.push(s[i]);
        if(s[i] == 'K') ost_k++;
        if(s[i] == 'S') ost_s++;
    }
    while(true){
        
        
        if(q.front() == 'K'){
            if(cnt_k >= 1){
                cnt_k--;
                ost_k--;
                q.pop();
            } else{
                q.push('K');
                q.pop();
                cnt_s++;
             
                p_k++;
            }
            
        } else{
            if(cnt_s >= 1){
                cnt_s--;
                ost_s--;
                q.pop();
            } else{
                q.push('S');
                q.pop();
                cnt_k++;
              
                p_s++;
            }
        }
       
        if(ost_k <= 0 or ost_s <= 0){
            if(p_k > p_s){
                cout << "KATSURAGI" << ENDL;
            return 0;
            } else if(p_k < p_s){
                 cout << "SAKAYANAGI" << ENDL;
            return 0;
            }
        }
       
    }
    


    endd
}