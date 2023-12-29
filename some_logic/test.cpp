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

int n, m;
vector<vector<int>> g;
vector<vector<int>> g2;
vector<bool> visited;
vector<int> top_sort;
vector<int> cost;
vector<int> path;

void dfs(int v){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(!visited[vertex]) dfs(vertex);
    }
    top_sort.pb(v);
}

void get_path(int v){

    visited[v] = true;
    path.pb(v);
    if(v == 1){
        return;
    }
    for(auto vertex : g2[v]){
        if(cost[vertex] + 1 == cost[v] and !visited[vertex]){
            get_path(vertex);
            return;
        }
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    cin >> n >> m;
    g = vector<vector<int>>(n + 1);
    g2 = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1);
    cost = vector<int>(n + 1, INT_MIN);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g2[b].pb(a);
    }
    dfs(1);
    
    reverse(all(top_sort));
    if(!visited[n]){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cost[1] = 0;
    for(auto vertex : top_sort){
        for(auto v : g[vertex]){
            cost[v] = max(cost[v], cost[vertex] + 1);
        }
    }
    visited = vector<bool>(n + 1);

    get_path(n);
    cout << path.size() << ENDL;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
    endd
}