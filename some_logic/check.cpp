#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


vector<int> path;

void rec(vector<vector<pair<int, int> > > &g, vector<int> &cost, int v, vector<bool> & visited){

    
    if(visited[v])
        return;
    path.pb(v);
    visited[v] = true;
    if(v <= 1){
        return;
    }
    for(auto vertex : g[v]){
        if(visited[vertex.ff]) continue;
        if(cost[vertex.ff] + vertex.ss == cost[v]){
            rec(g, cost, vertex.ff, visited);
            return;
        }
    }
    
}
vector<int> top_sort;
void get_top_sort(vector<vector<pair<int, int> > > &g, int v, vector<bool> & visited){
    visited[v] = true;
    for(auto vertex : g[v]){
        if(!visited[vertex.ff]){
            get_top_sort(g, vertex.ff, visited);
        }
    }
    top_sort.pb(v);
}
signed main(){
    
    goodluck


    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n + 1);

    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }
    if(g[n].size() == 0){
        cout << -1;
        return 0;
    }
    vector<int> cost(n + 1, LLONG_MAX);
    
    priority_queue<pair<int, int>> pq;

    vector<bool> visited(n + 1);
    // pq.push({0, 1});
    cost[1] = 0;
    get_top_sort(g, 1, visited);
    // while(!pq.empty()){
    //     int vertex = pq.top().ss;
    //     pq.pop();
    //     if(visited[vertex]) continue;
    //     visited[vertex] = true;
        // for(auto v : g[vertex]){
        //     int money = v.ss;
        //     int to_go = v.ff;
        //     if(money + cost[vertex] < cost[to_go]){
        //         cost[to_go] = money + cost[vertex];
        //     }
        //     pq.push({-cost[to_go], to_go});
        // }
    // }
    reverse(all(top_sort));
    for(auto v : top_sort) cout << v << " ";cout << ENDL;
    for(auto vertex : top_sort){
        for(auto v : g[vertex]){
            int money = v.ss;
            int to_go = v.ff;
            if(money + cost[vertex] < cost[to_go]){
                cost[to_go] = money + cost[vertex];
            }
        }
    }

    if(cost[n] == LLONG_MAX){ 
        cout << -1 << ENDL;
        return 0;
    }
    visited = vector<bool>(n + 1);
    rec(g, cost, n, visited);
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }

    endd
}