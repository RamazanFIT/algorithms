#include <bits/stdc++.h>

using namespace std;

signed main(){
    
    int n;
    cin >> n;
    int m;
    cin >> m;
                    // v     cost 
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        g[a].push_back(make_pair(b, cost));
        g[b].push_back(make_pair(a, cost)); // undirect graph
    }
    vector<int> cost(n + 1, INT_MAX);
    vector<bool> visited(n + 1, 0);
    cost[1] = 0;
    // 1 -> n 
    for(int i = 0; i < n; i++){ // n для каждой вершины 
        int min_cost_of_vertex = INT_MAX; // к максу чтобы найти min value in cost vector
        int min_vertex = -1;
        for(int j = 1; j < cost.size(); j++){
            // if not visited -> update min_vertex 
            if(!visited[j] and min_cost_of_vertex > cost[j]){
                min_cost_of_vertex = cost[j];
                min_vertex = j; // j - each vertex in graph
            } // находит минимальную вершину в массиве cost
        }
        visited[min_vertex] = true;
        for(int j = 0; j < g[min_vertex].size(); j++){
            if(cost[min_vertex] + g[min_vertex][j].second < cost[g[min_vertex][j].first]){
                cost[g[min_vertex][j].first] = cost[min_vertex] + g[min_vertex][j].second;
            } // дать соседям шанс на изменение в лучшую сторону 
        } // пробегается по соседям и улучшает их 
    }
    // cout << cost[n];  // O(n * n) 
    if(cost[n] == INT_MAX){
        cout << "NO path";
    } else{
        cout << cost[n];
    }
    
}