#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int mod = 1e9 + 7;
int ans = 0;
void dfs(vector<vector<int>> &g, int v, vector<bool> &visited){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(vertex == (g.size() - 1)){
            ans = (ans % mod + 1) % mod;
            // return;
            continue;
        }
        if(visited[vertex]) continue;

        dfs(g, vertex, visited);
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
    }

    vector<bool> visited(n + 1);
    // vector<int> ways(n + 1);
    // queue<int> q;
    // q.push(1);
    
    dfs(g, 1, visited);
    cout << ans << ENDL;
    

    endd
}