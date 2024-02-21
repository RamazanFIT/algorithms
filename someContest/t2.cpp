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

vector<int> in, out, fup, fin;
vector<vector<int>> cond, up, g;
vector<set<int>>g2;
vector<bool> visited, visited_mark, visited2;
vector<int> height;
int l;
int T = 0;
int cl = 0;
vector<int> color;


void dfs2(int v, int u, int h){
    in[v] = T++;
    up[v][0] = u;
    height[v] = h;
    visited2[v] = true;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(auto w : g2[v]){
        if(w != u and !visited2[w]){
            dfs2(w, v, h + 1);
        }
    }
    out[v] = T++;
}

bool isUpperThanB(int a, int b){
    return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b){
    if(isUpperThanB(a, b)) return a;
    if(isUpperThanB(b, a)) return b;
    
    for(int i = l; i >= 0; i--){
        if(!isUpperThanB(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}


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
    fin[v] = fup[v] = T++;
    
    bool flag = true;
    
    for(auto w : g[v]){
        if(flag and w == u) {flag = false; continue;}   

        if(!visited[w]) {
            dfs(w, v);
            fup[v] = min(fup[v], fup[w]);
        } else{
            fup[v] = min(fup[v], fin[w]);
        }
    }
    if(fup[v] == fin[v] and v != u){ // or >= тоже подейдет(но такого никогда не будет)
        mark(v, u, fin[v]);
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    int x;
    cin >> x;
    g  = vector<vector<int>>(n + 1);
    g2 = vector<set<int>>(n + 1);
    l = log2(n + 10); 
    up = vector<vector<int>>(n + 1, vector<int>(l * 2));
    fin = fup = in = out = vector<int>(n + 1);
    visited2 = visited_mark = visited = vector<bool>(n + 1);
    color = height = vector<int>(n + 1);
    vector<pair<int, int>> list_g;
    T = 0;
    cl = 0;
    color = vector<int>(n + 1);
    repeat(m){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        list_g.pb({a, b});
    }


    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i, i);
    }


    T = 0;
    for(auto it : list_g){
        g2[color[it.first]].insert(color[it.second]);
        g2[color[it.second]].insert(color[it.first]);
    }
    dfs2(color[x], color[x], 0);
    // for(int i = 1; i <= n; i++){
    //     cout << i << " " << color[i] << ENDL;
    // }
    
    int q;cin >> q;
    repeat(q){
        int a, b;
        cin >> a >> b;
        cout << height[lca(color[a], color[b])] << ENDL;
        // cout << lca(color[a], color[b]) << ENDL;
    }

    // cout << lca(1, 5);


}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    solve();
    


    endd
}