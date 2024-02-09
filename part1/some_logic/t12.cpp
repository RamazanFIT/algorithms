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
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        for(int j = x; j <= y; j++){
            for(int k = j + 1; k <= y; k++){
                g[j].pb({k, cost});
                g[k].pb({j, cost});
            }
        }
    }
    vector<pair<int, int>> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<bool> visited(n + 1);
    pq.push({0, {1, 1}});
    int sum = 0;
    for(int z = 0; z < n; z++){
        pair<int, pair<int, int>> info = pq.top(); pq.pop();
        
        int w = info.first;
        int v = info.ss.ff;
        int u = info.ss.ss;
        sum += w;
        cout << v << " " << u << ENDL;
        visited[u] = true;

        for(auto vertex : g[u]){
            if(!visited[vertex.ff]){
                pq.push({-vertex.ss, {u, vertex.ff}});
            } else{

;            }
        }
    }
    cout << sum << ENDL;
    endd
}