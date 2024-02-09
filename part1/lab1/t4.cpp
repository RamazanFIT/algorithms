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

    
    string a, b;
    cin>>a>>b;
    stack<int> st1;

    stack<int> st2;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '#'){
            if(not st1.empty())
            st1.pop();
        }
        else
        st1.push(a[i]);
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '#'){
            if(not st2.empty())
            st2.pop();
        }
        else
        st2.push(b[i]);
    }
    if(st1.size() != st2.size()){
        cout << "NO" << ENDL;
        return 0;
    }
    while(!st1.empty() and !st2.empty()){
        if(st1.top() != st2.top()){
            cout << "No" << ENDL;
            return 0;
        }
        st1.pop();
        st2.pop();
    }
    cout << "Yes" << ENDL;

    endd
}