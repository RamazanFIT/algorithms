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
int T = 0;
vector<bool> visited, colorVisited;
vector<int> color, in, up;
vector<vector<int>> g;
vector<set<int>> g2;

void paint(int v, int u, int cl){
    if(colorVisited[v]) return;
    colorVisited[v] = true;
    color[v] = cl;
    for(auto w : g[v]){
        if(w == u) continue;
        paint(w, v, cl);
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
        if(flag and w == u) {flag = false;continue;}
        
        if(!visited[w]){
            dfs(w, v);
            up[v] = min(up[v], up[w]);
        } else{
            up[v] = min(up[v], in[w]);
        }
    }
    if(up[v] == in[v] and u != v){
        // bridge 
        paint(v, u, in[v]);
        // cout << v << " " << u << ENDL;
    }
    
}

void solve(int ccase){
    int n, m;cin >> n >> m;
    g = vector<vector<int>>(n + 1);
    color = in = up = vector<int>(n + 1);
    g2 = vector<set<int>>(n + 1);
    visited = colorVisited = vector<bool>(n + 1);
    T = 0;
    vector<pair<int, int>> gg;
    repeat(m){
        int a, b;cin>>a>>b;
        a++;b++;
        g[a].pb(b);g[b].pb(a);
        gg.pb({a, b});
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, i);
        }
    }

    for(auto it : gg){
        if(color[it.first] == color[it.second]) continue;
        g2[color[it.first]].insert(color[it.second]);
        g2[color[it.second]].insert(color[it.first]);
    }
    
    int cnt = 0;
    
    for(auto it : g2){
        if(it.size() == 1) cnt++;
    }

    cout << "Case " << ccase + 1 << ": " << cnt % 2 + cnt / 2 << ENDL;
    // cout << cnt << ENDL;
    // for(int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for(auto it : g2[i]){
    //         cout << it << " ";
    //     }
    //     cout << ENDL;
    // }
    // for(int i = 1; i <= n; i++){
    //     cout << color[i] << " ";
    // }
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin >> t;
    repeat(t) solve(_);
    


    endd
}