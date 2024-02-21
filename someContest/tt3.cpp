// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    char a;
    cin >> a;
    int cnt = 0;
    // map<char, vector<int>> mapa;
    vector<pair<int, pair<char, int>>> massive;
    for(int i = 0; i < 2 * n; ++i){
        char mask;
        char type;
        // cin >> mask >> type;
        string s;
        cin >> s;
        mask = s[0];
        type = s[1];
        // mapa[type].pb(int(mask - '0'));
        massive.pb({})

    }
    

}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t) solve();

    endd
}