#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    string s;
    cin >> s;
    int x;
    cin >> x;
    int cnt = 0;
    int size = s.size();
    s += '$';//skip delete on the last place in the string 
    vector<char> st;

    for(auto it : s){
        while(!st.empty() && (int(st.back()) > int(it)) && (cnt + size < x)){
            cnt += size;
            size--;
            st.pop_back();
        }
        st.push_back(it);
    }
    // cout << size - cnt - size + x - 1;
    cout << st[size - cnt - size + x - 1];
    // for(int i = 0; i < st.size(); i++){
    //     cout << st[i] << " ";
    // }

    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}