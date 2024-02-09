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
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int cost;
        cin >> cost;
        g[a].pb({b, cost});
        g[b].pb({a, cost});
       
    }
    vector<int> cost_to_vertex(n + 1, 1e9 + 7);
    vector<int> from_where(n + 1, -1);
    set<pair<int, int>> st;
    st.insert({0, 1});
    cost_to_vertex[1] = 0;
    long long summary_cost = 0;
    vector<bool> visited(n + 1);
    while(!st.empty()){
        int x = st.begin()->first;
        int v = st.begin()->second;
        st.erase(st.begin());
        if(visited[v]) continue;
        summary_cost += x;
        
        // if(from_where[v] != -1){
        //     cout << from_where[v] << " " << v << endl;
        // }
        visited[v] = true;
        for(auto vertex : g[v]){
            int to = vertex.first;
            int cost = vertex.second;
            if(cost_to_vertex[to] > cost){
                st.erase({cost_to_vertex[to], to});
                cost_to_vertex[to] = cost;
                from_where[to] = v;
                st.insert({cost_to_vertex[to], to});
            }
        }
    }
    cout << summary_cost;

    endd
}