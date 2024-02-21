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
vector<bool> isCutPoint;
int T = 0;


int dfs(int v, int u){
    // u
    // .
    // .
    // .
    // v
    visited[v] = true;
    in[v] = up[v] = T++;
    int baby = 0;
    for(auto w : g[v]){
        if(w == u) continue;
        if(!visited[w]) {
            baby++;
            dfs(w, v);
            up[v] = min(up[v], up[w]);
        } else{
            up[v] = min(up[v], up[w]);
        }
        if(up[w] >= in[v]){
            isCutPoint[v] = true;
        }
    } 
    return baby > 1;
}



void solve(int ccase){
    int n, m;cin>>n>>m;

    g = vector<vector<int>>(n + 1);
    timer = up = in = color = vector<int>(n + 1);
    isCutPoint = visited_mark = visited = vector<bool>(n + 1);
    T = 0;

    repeat(m){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            isCutPoint[i] = dfs(i, i);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(isCutPoint[i]) cnt++;
    cout << "Case " << ccase + 1 << ": " << cnt << ENDL;
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int x;cin>>x;
    repeat(x)
    solve(_);

    endd
}