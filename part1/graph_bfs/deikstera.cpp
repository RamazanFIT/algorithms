#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

map<pair<int, int>, int> mapa;
unordered_map<int, vector<int>> graph;
vector<int> path;

void rec(int vert, int len, bool * used, int * L){
    // cout << vert << " ";
    if(vert == 1) return;
    for(int i = 0; i < graph[vert].size(); i++){
        if(used[graph[vert][i]]) continue;
        if(len - mapa[{vert, graph[vert][i]}] == L[graph[vert][i]]){
            path.push_back(graph[vert][i]);
            used[vert] = true;
            rec(graph[vert][i], L[graph[vert][i]], used, L);
            return;
        }
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);
    
    int v;
    int m;
    cin >> v >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        mapa[{a, b}] = w;
        mapa[{b, a}] = w;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }

    bool used[v + 1];
    for(int i = 0; i < v + 1; i++){
        used[i] = 0;
    }


    int L[v + 1];
    
    for(int i = 1; i <= v; i++) L[i] = LONG_LONG_MAX;
    L[1] = 0;
    priority_queue<int> q;
    q.push(1);
    
    while(q.size()){
        int vertice = q.top();
        q.pop();
        for(int j = 0; j < graph[vertice].size(); j++){
            if(L[vertice] + mapa[{vertice, graph[vertice][j]}] < L[graph[vertice][j]]){
                L[graph[vertice][j]] = L[vertice] + mapa[{vertice, graph[vertice][j]}];
                q.push(graph[vertice][j]);
            }
        }
    }

    
    path.push_back(v);
    
    rec(v, L[v], used, L);
    if(L[v] == LONG_LONG_MAX){
        cout << -1 << ENDL;
        return 0;
    }
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] <<" ";
    }
    


    endd
}

