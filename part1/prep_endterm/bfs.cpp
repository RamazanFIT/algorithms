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
        g[b].pb(a);
    }
    queue<int> q;
    q.push(1);
    vector<int> visited(n + 1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(visited[v]) continue;
        visited[v] = true;
        cout << v << " ";
        for(auto vertex : g[v]){
            q.push(vertex);
        }
    }
    // O(n + m)


    endd
}