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

signed main(){
    
    goodluck
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;
    int a,b;
    cin >> a >> b;
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        g[a].pb({b, cost});
        g[b].pb({a, cost});
    }
    priority_queue<pair<int, int>> pq;
    vector<int> ot(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);
    pq.push({0, a});
    while(!pq.empty()){
        int v = pq.top().ss;
        int w = -pq.top().ff;
        pq.pop();
        for(auto vertex : g[v]){
            if(vertex.ss + w < dist[vertex.ff]){
                dist[vertex.ff] = vertex.ss + w;
                pq.push({-(dist[vertex.ff]), vertex.ff});
                ot[vertex.ff] = v;
            }
        }
    }
    ot[a] = -1;
    if(dist[b] == INT_MAX){
        cout << -1;
        exit(0);
    } else{
        cout << dist[b];
    }
    cout << ENDL;
    vector<int> path;
    int v = b;
    path.pb(v);

    while(true){
        int u = ot[v];
        if(u == -1) break;
        path.pb(u);
        v = u;
    }
    reverse(all(path));
    for(auto u : path){
        cout << u << " ";
    }
    


    endd
}