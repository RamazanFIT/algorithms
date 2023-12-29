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
        int v = st.begin()->second;
        int w = st.begin()->first;
        st.erase(st.begin());
        if(visited[v]) continue;
        visited[v] = true;
        if(from_where[v] != -1){
            cout << v << " " << from_where[v] << ENDL;
        }
        for(auto vertex : g[v]){
            if(cost_to_vertex[vertex.first] > vertex.second){
                st.erase({cost_to_vertex[vertex.ff], vertex.first});
                cost_to_vertex[vertex.first] = vertex.second;
                from_where[vertex.first] = v;
                st.insert({cost_to_vertex[vertex.ff], vertex.first});
            }
        }
    }
    // O(m * log(n))
    
    


    endd
}