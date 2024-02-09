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
int n, m;
vector<bool> visited;
vector<int> topsort;

void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;
    for(auto vertex : g[v]){
        dfs(vertex);
    }
    // cout << v << " ";
    topsort.pb(v);  // O(n + m)
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    
    cin >> n >> m;
    g = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
    }
    dfs(1);
    reverse(all(topsort));
    for(auto it : topsort){
        cout << it << " ";
    }
    // O(n + m) 

    endd
}