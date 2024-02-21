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
vector<int> timer, up, in, color;
vector<bool> visited, visited_mark;
vector<vector<int>> g;
vector<pair<int, int>> bridges;
int T = 0;


void mark(int v, int u, int cl){
    if(visited_mark[v]) return;
    visited_mark[v] = true;
    color[v] = cl;
    for(auto w : g[v]){
        if(w == u) continue;
        mark(w, v, cl);
    }
}

void dfs(int v, int u){
    // u
    // .
    // .
    // .
    // v
    visited[v] = true;
    in[v] = up[v] = T++;
    
    bool flag = true;
    
    for(auto w : g[v]){
        if(flag and w == u) {flag = false; continue;}   

        if(!visited[w]) {
            dfs(w, v);
            up[v] = min(up[v], up[w]);
        } else{
            up[v] = min(up[v], in[w]);
        }
    }
    if(up[v] == in[v] and v != u){ // or >= тоже подейдет(но такого никогда не будет)
        // That is bridge 
        mark(v, u, in[v]);
        if(v < u)
        bridges.pb({v, u});
        else
        bridges.pb({u, v});
    }
}



void solve(){
    int n, m;cin>>n>>m;

    g = vector<vector<int>>(n + 1);
    timer = up = in = color = vector<int>(n + 1);
    visited_mark = visited = vector<bool>(n + 1);
    
    map<pair<int, int>, int> mapa;
    repeat(m){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        if(x < y)
        mapa[{x, y}] = _ + 1;
        else
        mapa[{y, x}] = _ + 1;

    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, i);
        }
    }

    // cout << bridges.size() << ENDL;
    set<int> answere;

    for(auto it : bridges){
        // answere.insert(mapa[it]);
        cout << it.first << " " << it.second << ENDL;
    }
    // cout << answere.size() << ENDL;
    // for(auto it : answere){
    //     cout << it << " ";
    // }
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    solve();

    endd
}