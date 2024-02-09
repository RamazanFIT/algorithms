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

    int n;
    cin >> n;
    // vector<int> eks;
    vector<vector<pair<int, int>>> g(n + 1);   
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            if(a != -1)
            g[i].pb({j, a});
        }
    }
    int ans1 = INT_MAX;
    int ans2 = INT_MIN;
    for(int i = 1; i <= n; i++){
        priority_queue<pair<int, int>> pq;
        vector<int> dist(n + 1, INT_MIN);
        dist[i] = 0;
        vector<bool> bolean(n + 1);
        pq.push({0, i});
        int u = INT_MIN;
        while(!pq.empty()){
            int v = pq.top().ss;
            int w = pq.top().ff;
            pq.pop();
            if(bolean[v]) continue;
            if(w != 0)
            u = max(u, w);
            bolean[v] = true;
            for(auto vertex : g[v]){
                if(vertex.ss + w > dist[vertex.ff]){
                    dist[vertex.ff] = vertex.ss + w;
                    pq.push({dist[vertex.ff], vertex.ss});
                }
            }
        }
        ans1 = min(ans1, u);
        ans2 = max(ans2, u);
        
    }
    cout << ans2 << ENDL << ans1 << ENDL;

    endd
}