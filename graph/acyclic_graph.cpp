#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define vertex_t int
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


class Oriented_Graph{
public:
    int vertex_number = 0;
    int edges_number = 0;
    //список смежности для каждой вершины(просто соседи какого-то vertex)
    vector< set < vertex_t > > sets_of_neighbour;
    void input(){
        cin>>vertex_number>>edges_number;
        sets_of_neighbour.clear();
        sets_of_neighbour.resize(vertex_number);
        for(int i = 0; i < edges_number; i++){
            vertex_t a, b;
            cin>>a>>b;
            sets_of_neighbour[a].insert(b);
            
            // sets_of_neighbour[b].insert(a);
        }   

    }

    void output() const{
        cout << "Number of vertex: " << vertex_number << ENDL;
        cout << "Number of edges: " << edges_number << ENDL;
        for(int i = 0; i < vertex_number; i++){
            cout << i << " : [";
            for(auto neighbour : sets_of_neighbour[i]){
                cout << neighbour << " ";
            }
            cout << "]"<< ENDL;
        }
    }
    


};

// DAG - directed acyclic graph
bool check_DAG(const Oriented_Graph &graph, 
            vertex_t start_vertex,
            vector<bool> &used 
){
    used[start_vertex] = 1;
    // cout << start_vertex << " ";
    for(auto neighbour : graph.sets_of_neighbour[start_vertex]){
        // if(neighbour == start_vertex) continue;
        if(used[neighbour]){
            return false;
        }
        return check_DAG(graph, neighbour, used);
    }
    return true;
}


signed main(){
    
    // goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    Oriented_Graph g;
    g.input();
    g.output();
    // cout << "Enter a start vertex: " << ENDL;
    // vertex_t start;
    // cin>>start;
    bool is_DAG = true;
    vector<bool> bolean(g.vertex_number, 0);
    for(vertex_t vertex = 0; vertex < g.vertex_number; vertex++){
        if(bolean[vertex]) continue;
        is_DAG &= check_DAG(g, vertex, bolean);
        if(not is_DAG){
            break;
        }
    }
    if(is_DAG){
        cout << "Acyclic graph" << ENDL;
    } else cout << "Cyclic graph" << ENDL;
    
    
    


    endd
}
