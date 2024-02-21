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
vector<int> in, up, color;
vector<vector<int>> g;
vector<bool> visited, visitedColor;
set<pair<int, int>> bridges;
int T = 0;
int cl = 2;


void paint(int v, int u, int coo){
    if(visitedColor[v]) return;
    visitedColor[v] = true;
    color[v] = coo;
    for(auto w : g[v]){
        if(w == u) continue;
        paint(w, u, coo);
    }
}

void dfs(int v, int u){
    // u 
    // .
    // .
    // .
    // v
    visited[v] = true;
    bool flag = true;

    up[v] = in[v] = T++;
    for(auto w : g[v]){
        if(flag and w == u) {flag = false; continue;}

        if(!visited[w]){
            dfs(w, v);
            up[v] = min(up[v], up[w]);
        } else{
            up[v] = min(up[v], in[w]);
        }
    }
    if(up[v] == in[v] and v != u){
        // paint(v, u, cl++);
        if(v < u)
        bridges.insert({v, u});
        else
        bridges.insert({u, v});

    }
}
int cnt = 1;
void touch(int v){
    if(visitedColor[v]) return;
    visitedColor[v] = true;
    color[v] = cnt;

    for(auto w : g[v]){
        if(bridges.find({min(w, v), max(w, v)}) == bridges.end()){
            touch(w);
        }
    }
}   
void solve(){
    int n, m;cin>>n>>m;
    g = vector<vector<int>>(n + 1);
    visitedColor = visited = vector<bool>(n + 1);
    color = vector<int>(n + 2, 1);
    in = up = vector<int>(n + 1);
    T = 0;
    
    repeat(m){
        int a, b;cin>>a>>b;g[a].pb(b);g[b].pb(a);
    }
    for(int i = 1; i <= n; i++) if(!visited[i]) dfs(i, i);

    for(int i = 1; i <= n; i++){
        if(!visitedColor[i]){
            touch(i);
            cnt++;
        }
    }
    cout << cnt - 1 << ENDL;
    for(int i = 1; i <= n; i++) cout << color[i] << " ";

}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    solve();
    


    endd
}