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

    string s = "sheriff";

    string a;
    cin >> a;
    map<char, int> mapa;
    for(int i = 0 ;i < a.size(); i++){
        if(s.find(a[i]) != -1){
            mapa[a[i]]++;
        }
    }
    mapa['f'] = mapa['f'] / 2;
    int ans = mapa['s'];
    for(auto it : mapa){
        ans = min(ans, it.second);
    }
    cout << ans << ENDL;
    


    endd
}