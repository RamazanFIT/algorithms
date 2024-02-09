#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int path = 0;
bool flag = false;
int n, A, B;

struct Graph{

    int n;
    vector<set<int> > graph;
    Graph(int n){
        this->n = n;
    }
    void input(){
        graph.clear();
        graph.resize(n + 1);
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            graph[a].insert(b);
            graph[b].insert(a);

        }
    }

};


void dfs(int current_vert, Graph & g, vector<bool> & boolean, int prev){
    boolean[current_vert] = 1;
    path++;
    cout << current_vert << " : " << prev << ENDL;
    for(auto vertice : g.graph[current_vert]){
        if(vertice == A) continue;
        if(boolean[vertice] and path > 2 and prev != vertice){
            // cout << current_vert << " : " << prev << ENDL;
            flag = true;
            return;
        } else if(prev != vertice){
            dfs(vertice, g, boolean, current_vert);
        }
    }
}


void solve(){
    // int n, A, B;
    cin >> n >> A >> B;
    Graph g(n);
    g.input();

    for(auto vertice : g.graph[B]){
        if(vertice == A and g.graph[B].size() == 1){
            cout << "NO" << ENDL;
            return;
        }
    }

    vector<bool> boolean(n + 1, false);

    dfs(B, g, boolean, INT_MAX);

    if(flag){
        cout << "YES" << ENDL;
    } else{
        cout << "NO" << ENDL;
    }

    flag = false;
    path = 0;

}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}