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
                    // cost vertex
    priority_queue<pair<int, int>> pq; // 
    // priority_queue отсортировывает по убыванию (В начале самое наибольшее а потом наимешьшее)
    vector<int> cost(n + 1, INT_MAX); // 1
    cost[1] = 0;
    // 1 > n 
    pq.push({0, 1});
    while(!pq.empty()){
        int v = pq.top().second;
        int w = -pq.top().first; // weight у вершины v сумма
                            // стоимостей ребер по которому мы дошли до v
        pq.pop();
        for(int i = 0; i < g[v].size(); i++){
            int money = g[v][i].second; // стоимость ребра которое 
                                    // соединяет вершиnu V with vertex
            int vertex_neighboor = g[v][i].first;
            if(money + w < cost[vertex_neighboor]){ // w weight 
                cost[vertex_neighboor] = money + w;
                pq.push({-cost[vertex_neighboor], vertex_neighboor});
                // insert to find the lowest vertex  
                // я беру обновленную вершину с его ценой к кладу его на рассмотрение в pq
                // тк может быть он является фаворитом у которой самая минимальная цена 
            }
        }
    }
    // 1 2 12 3
    // 12 3 2 1 //
    // -12 -3 -2 -1
    // -1 -2 -3 -12 // vot tak
    
    
}