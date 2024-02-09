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

    string s;
    cin>>s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        } else if(st.top() == s[i]){
            st.pop();
        } else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        cout << "YES" << ENDL;
    } else{
        cout << "NO" << ENDL;
    }
    


    endd
}