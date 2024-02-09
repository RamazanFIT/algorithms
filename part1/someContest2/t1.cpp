// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
#define int ll
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int, vector<int>> mapa;
    // 0 n 
    repeat(n){
        int a;
        cin >> a;
        if(mapa[a].empty()) mapa[a].pb(-1);

        mapa[a].pb(_);
    }
    int ans = INT_MAX;
    for(auto it : mapa){
        mapa[it.first].pb(n);
        vector<int> v = mapa[it.first];
        int cnt = 0;
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i + 1] - v[i] >= 2){
                cnt++;
                // cout << v[i + 1] << " " << v[i] << ENDL;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << ENDL;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t)solve();
    


    endd
}
