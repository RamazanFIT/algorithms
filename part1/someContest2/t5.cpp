// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> g(n + 1);

    repeat(m){
        int u, v, cs;
        cin >> u >> v >> cs;
        g[u].pb({v, cs});
    }

    priority_queue<pair<int, int>> pq;
    vector<int> price(n + 1, LLONG_MAX);
    vector<int> visited(n + 1);
    pq.push({0, 1});
    price[1] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(visited[v]) continue;
        visited[v] = true;
        for(auto vertex : g[v]){
            if(price[vertex.ff] == LLONG_MAX or (price[vertex.ff] > cost + vertex.ss)){
                price[vertex.ff] = cost + vertex.ss;
                pq.push({-price[vertex.ff], vertex.ff});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << price[i] << " ";


    endd
}