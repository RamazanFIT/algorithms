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
    vector<int> ways(n + 1);
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        if(visited[vertex]) continue;
        visited[vertex] = true;
        for(auto v : g[vertex]){
            // ways[v] = (ways[v] % mod + 1ll + ways[vertex] % mod) % mod;
            if(visited[v]) continue;
            ways[v] = ways[v] + ways[vertex] + 1;
            q.push(v);
        }
    }
    cout << ways[n] << ENDL;
    // for(int i = 1; i <= n; i++){
    //     cout << i << " ";
    // } cout << endl;
    // for(int i = 1; i <= n; i++){
    //     cout << ways[i] << " ";
    // }
    

    endd
}