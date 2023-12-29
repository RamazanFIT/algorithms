#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);  // 1 2 1
    // n - cnt of vertex
    // m - cnt of edges
    // a b cost 
    // g[1].push_back(make_pair(2, 1));
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        g[a].push_back(make_pair(b, cost));
        g[b].push_back(make_pair(a, cost));
    }
    // INT_MAX - 2147483647 
    vector<int> cost_to_vertex(n + 1, INT_MAX); // цену ребра которое в mst из которой исх
    vector<int> from_where(n + 1, -1);
    set<pair<int, int>> st;
    // cost_to_vertex, vertex 
    vector<bool> visited(n + 1 , 0); // n - 1  0 1 2 3 4 5 
    st.insert(make_pair(0, 1));
    int sum_of_MST = 0; // сумму всех ребер которое соединяет MST
    while(not st.empty()){
        int v = st.begin()->second; // vertex
        int w = st.begin()->first; // cost
        st.erase(st.begin()); // delete the min cost vertex
        if(visited[v] == true){
            continue;
        }
        visited[v] = true;
        sum_of_MST += w;
        if(from_where[v] != -1){
            cout << v << " " << from_where[v] << endl;
        }
        // for(auto vertex : g[v]){
        //     int vertex_to = vertex.first;
        //     int weight = vertex.second;
            // if(cost_to_vertex[vertex_to] > weight){
            //     st.erase(make_pair(cost_to_vertex[vertex_to], vertex_to));
            //     cost_to_vertex[vertex_to] = weight;
            //     from_where[vertex_to] = v;
            //     st.insert({cost_to_vertex[vertex_to], vertex_to});
            // }
        // }
        for(int i = 0; i < g[v].size(); i++){
            int vertex_to = g[v][i].first;
            int weight = g[v][i].second;
            if(cost_to_vertex[vertex_to] > weight){
                st.erase(make_pair(cost_to_vertex[vertex_to], vertex_to));
                cost_to_vertex[vertex_to] = weight;
                from_where[vertex_to] = v;
                st.insert({cost_to_vertex[vertex_to], vertex_to});
            }
        }
    }
    cout << sum_of_MST;
    // O(m * log(n)) Prima algorithm  
    // O(n * n) 
    // n * n < m * log(n) = n * n * log(n);
    // m = n * n 
}