#include <bits/stdc++.h>

using namespace std;

int main(){
    
    
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> g;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
                                // cost     vertex1 vertex2
        g.push_back(make_pair(cost, make_pair(a, b))); // oriented     not 
        g.push_back(make_pair(cost, make_pair(b, a)));
    }
    
    vector<int> cost(n + 1, INT_MAX);
    cost[1] = 0;
    int x = -1;
    for(int i = 0; i < n; i++){ // n - 1  
        x = -1;
        for(int j = 0; j < g.size(); j++){ //  g.size(); - cnt of edges
            int a = g[j].second.first; // вершина 1
            int b =  g[j].second.second; // вершина 2
            int money = g[j].first; // его цена
            if(cost[a] != INT_MAX){
                if(cost[a] + money < cost[b]){
                    cost[b] = cost[a] + money; 
                    x = 77;
                }
            }
        } // просматривает все edge и ищет способ улучшить любую вершину 
    }
    if(x == 77){
        cout << "There exists negative cycle";
    }
    // 1---2---3----4 
    // n = 4 
    // n - 1 
    // cout << cost[n];
    // ford - negative edges 
    // Дейкстера - применим только + ребрам(Там где где - ребра) 
    // Алгоритм дейстеры просматривает не весь граф каждый раз и не 
    // пытается просмореть все ходы
    // А он просто берет и просмотривает кусочек 
    // графа там где до этой вершины наименьшее стоимость на данный момомен


}