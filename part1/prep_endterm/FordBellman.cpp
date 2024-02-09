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
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> g;
    vector<int> dist(n + 1, INT_MAX);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int cost;cin >> cost;
        g.push_back({cost, {a, b}});
        g.push_back({cost, {b, a}});
    }
    dist[1] = 0;
    for(int i = 0; i < n - 1; i++){
        for(auto it : g){
            int u = it.ss.ff;
            int v = it.ss.ss;
            int w = it.ff;
            // if(dist[v] != INT_MAX)
            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] + w;
            }
        }
    }
    cout << dist[n];
    // O(n * m)


    endd
}