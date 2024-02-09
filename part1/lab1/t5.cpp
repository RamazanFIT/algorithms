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
    if(s.size() == 0){
        cout << "YES" << ENDL;return 0;
    } else if(s.size() == 1){
        cout << "NO" << ENDL;return 0;
    }
    st.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(!st.empty() and st.top() == s[i]){
            st.pop();
        } else{
            st.push(s[i]);
            
        }
    }
    string a = "";
    while(!st.empty()){
    
        a += st.top();
        st.pop();
    }
    string y = a + s;
    bool flag = true;

    for(int i = 0; i < y.size(); i++){
        if(y[i] != y[y.size() - 1 - i]) flag = false;
    }
    if(flag){
        cout << "YES" << ENDL;
    }
    else
    if(s.find(a) != -1){
        cout << "YES" << ENDL;
    } else{
        cout << "NO" << ENDL;
    }
    


    endd
}