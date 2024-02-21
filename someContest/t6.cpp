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
using namespace std;

vector<vector<int>> g;
vector<int> path;


void dfs(int v){
    while(!g[v].empty()){
        int u = g[v].back();
        g[v].pop_back();
        dfs(u);
    }
    path.pb(v);
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;cin>>n>>m;
    g = vector<vector<int>>(n + 1);
    vector<int> in(n + 1), out(n + 1);
    repeat(m){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        out[a]++;
        in[b]++;
    }

    if(out[1] < in[1] or out[n] > in[n] or abs(out[1] - in[1]) >= 2 or abs(out[n] - in[n]) >= 2){
        cout << "IMPOSSIBLE" << ENDL;
        return 0;
    }
    for(int i = 2; i < n; i++){
        if(in[i] != out[i]){
            cout << "IMPOSSIBLE" << ENDL;
            return 0;
        }
    }
    dfs(1);

    reverse(all(path));

    for(int i = 1; i <= n; i++){
        if(g[i].size() != 0){
            cout << "IMPOSSIBLE" << ENDL;
            return 0;
        }
    }

    if(path.back() != n){
        cout << "IMPOSSIBLE" << ENDL;
        return 0;
    }
    for(auto it : path) cout << it << " ";



    endd
}