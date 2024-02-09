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
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

set<pair<int, int>> ans;
int T = 0;
int n, m;

void dfs(vector<vector<int>> &g, int current, int from, 
        vector<bool> &visited, vector<int> &t_in, vector<int> &up){
    visited[current] = true;
    t_in[current] = T++;
    up[current] = t_in[current]; // INT_MAX
    for(auto vertex : g[current]){
        if(vertex == from){
            continue;
        }
        if(!visited[vertex]){
            dfs(g, vertex, current, visited, t_in, up);
            up[current] = min(up[current], up[vertex]);
        } else{
            up[current] = min(up[current], t_in[vertex]);
        }
    }
    if(up[current] >= t_in[current] and current != from){
        // ans.pb({from, current});
        if(from > current){
            ans.insert({current, from});
        } else{
            ans.insert({from, current});
        }
    }
}
void solve(int ccase){

    cin >> m;
    n = ccase;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> mapa;

    repeat(m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
        mapa[{a, b}] = _ + 1;
        mapa[{b, a}] = _ + 1;

    }
    vector<int> t_in(n);
    vector<int> up(n);
    vector<bool> visited(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(g, i, i, visited, t_in, up);
        }
    }
    cout << ans.size() << ENDL;
    set<int> kkkkkk;
    for(auto v : ans){
        // cout << v.first << " - " << v.second << ENDL;
        // cout << mapa[{v.first, v.second}] << ENDL;
        kkkkkk.insert(mapa[{v.first, v.second}]);
    }
    T = 0;
    for(auto it : kkkkkk){
        cout << it << ENDL;
    }
    ans.clear();
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int t;
    t = 1;

    // for(int i = 1; i <= t; i++){
        // solve();
    // }
    while(cin >> t){
        solve(t);
    }


    endd
}






