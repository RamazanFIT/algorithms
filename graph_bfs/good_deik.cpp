#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define INF INT_MAX
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

signed main(){
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n + 2);
    vector<int> cost(n + 2, INF);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        g[a].pb({b, 0});
        g[b].pb({a, 1});

    }
    // deque<int> dq;
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(n + 2, false);
    cost[1] = 0;
    // dq.push_back(1);
    pq.push({0, 1});
    while(!pq.empty()){
        // int vertex = dq.front();
        // dq.pop_front();
        int vertex = pq.top().ss;
        pq.pop();
        if(visited[vertex]) continue;
        visited[vertex] = true;
        for(auto v : g[vertex]){
            if(cost[vertex] + v.ss < cost[v.ff]){
                cost[v.ff] = cost[vertex] + v.ss;
                if(v.ss == 1){
                    // dq.push_back(v.ff);
                    pq.push({-cost[v.ff], v.ff});
                } else{
                    // dq.push_front(v.ff);
                    pq.push({-cost[v.ff], v.ff});

                }
            }
        }
    }
    if(cost[n] == INF){
        cout << -1 << ENDL;
    } else{
        cout << cost[n] << ENDL;
    }
    


    endd
}