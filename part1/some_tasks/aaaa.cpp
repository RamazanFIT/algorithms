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
vector<vector<pair<int, double>>> g;
vector<int> topsort_v;

void topsort(int v){
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;cin>>n>>m;
    g = vector<vector<pair<int, double>>>(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        double cost;
        cin >> a >> b >> cost;
        g[a].pb({b, cost / 100.0});
        g[b].pb({a, cost / 100.0});

    }
    
    priority_queue<pair<double, int>> pq;
    vector<double> dist(n + 1, -1);
    dist[1] = 1;
    pq.push({1, 1});
    while(!pq.empty()){
        int v = pq.top().ss; 
        double cost = pq.top().ff; pq.pop();
        for(auto vertex : g[v]){
            if(vertex.ss * cost > dist[vertex.ff]){
                
                dist[vertex.ff] = vertex.ss * cost;
                pq.push(
                    {dist[vertex.ff], vertex.ff}
                );
            }
        }
    }
    cout << fixed << setprecision(6) <<  dist[n] * 100.0 << " percent";
    // for(auto v : dist) cout << v << " ";


    endd
}