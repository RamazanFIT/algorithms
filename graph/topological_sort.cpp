#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

stack<int> path;

class Graph{
    public:
        int vertex_number = 0, edges_number = 0;
        vector<set<int> > graph;

        void input(){
            cin>>vertex_number >> edges_number;
            graph.resize(vertex_number + 1);
            for(int edges_cnt = 0; edges_cnt < edges_number; edges_cnt++){
                int a, b;
                cin>>a>>b;
                graph[a].insert(b);
            }
        }
        void output(){
            for(int i = 1; i <= vertex_number; i++){
                cout << i << ": ";
                for(auto it : graph[i]){
                    cout << it << " ";
                }
                cout << ENDL;
            }
        }

};


void topological_sort_dfs(vector<bool> & boolean, int current_vertex, Graph & graph){
    boolean[current_vertex] = true;

    for(auto vertex : graph.graph[current_vertex]){
        if(!boolean[vertex]){
            topological_sort_dfs(boolean, vertex, graph);
        }
    }
    path.push(current_vertex);
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    
    Graph g;
    g.input();
    vector<bool> boolean(g.vertex_number + 1, 0);
    g.output();
    // topological_sort_dfs(boolean, )
    for(int vertex = 1; vertex <= g.vertex_number; vertex++){
        if(!boolean[vertex])
        topological_sort_dfs(boolean, vertex, g);
    }
    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
    cout << ENDL;


    endd
}