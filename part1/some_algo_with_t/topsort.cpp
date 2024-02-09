#include <bits/stdc++.h>

using namespace std;

vector<int> topologicalsort;
vector<bool> visited;
vector<vector<int>> g;

void dfs(int v){
    if(visited[v] == true) return;
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int vertex = g[v][i];
        dfs(vertex);
    }
    topologicalsort.push_back(v);
}

int main(){
    

    // O(n + m) // O(n + m)
    // O(m)  
    // n << m 
    int n;
    cin >> n;
    int m;
    cin >> m;
    g = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(topologicalsort.begin(), topologicalsort.end());
    
    for(int i = 0; i < topologicalsort.size(); i++){
        cout << topologicalsort[i] << " ";
    }
}