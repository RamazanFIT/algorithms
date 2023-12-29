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
vector<vector<pair<int, int>>> g;
int n, m;
vector<bool> visited;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    cin >> n >> m;
    g = vector<vector<pair<int, int>>>(n + 1);
    visited = vector<bool>(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int cost;cin >> cost;
        g[a].pb({b, cost});
        g[b].pb({a, cost});
    }
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    while(!pq.empty()){
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        for(auto vertex : g[v]){
            if(dist[v] + vertex.ss < dist[vertex.first]){
                dist[vertex.first] = dist[v] + vertex.ss;
                pq.push({-(dist[vertex.first]), vertex.ff});
            }
        }
    }
    cout << dist[n];
    // O((n + m) * log(n))




    endd
}