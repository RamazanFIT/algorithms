#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<vector<int>> g;
set<pair<int, int>> check;
vector<pair<int, int>> ans;
vector<int> up;
vector<int> t_in;
int Timer;
vector<bool> visited;
bool flag = false;

void dfs(int v, int u){
    if(flag) return;
    t_in[v] = Timer++;
    up[v] = t_in[v];
    visited[v] = true;
    for(auto vertex : g[v]){
        if(vertex == u){
            continue;
        }
        if(!visited[vertex]){
            dfs(vertex, v);
            up[v] = min(up[v], up[vertex]);
            ans.pb({v, vertex});
        } else{
            up[v] = min(up[v], t_in[vertex]);
            if(t_in[vertex] < t_in[v])
            ans.pb({v, vertex});
        }

    }
    if(up[v] >= t_in[v] and (v != u)){
        // cout << v << " " << u << ENDL;
        flag = true;
    }
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    g = vector<vector<int>>(n + 1);
    up = vector<int>(n + 1);
    t_in = vector<int>(n + 1);
    Timer = 0;
    visited = vector<bool>(n + 1);
    map<pair<int, int>, int> ansss;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        ansss[{a, b}] = i + 1;
        ansss[{b, a}] = i + 1;
    }
    
    dfs(1, 1);
    if(flag){
        cout << 0;
        return 0;
    }
    cout << ans.size() << ENDL;
    for(auto it : ans){
        cout << it.first << " " << it.second << ENDL;
        // cout << ansss[{it.first, it.second}] << ENDL;
    }

    
    


    endd
}