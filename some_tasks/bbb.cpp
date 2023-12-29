#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(n) for(int mmm = 0; mmm < n; mmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
bool flag = true;
vector<vector<int>> g2;
vector<bool> tmp;
vector<bool> visited;

bool is_DAG(int v){
    tmp[v] = true;
    visited[v] = true;
    for(auto vertex : g2[v]){
        if(visited[vertex]){
            if(tmp[vertex]){
                return false;
            }
        } else{
             if(!is_DAG(vertex)){
                return false;
             }
        }
    }
    tmp[v] = false;
    return true;
}


signed main(){
    
    goodluck
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);

    int m, n;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> g;
    g2 = vector<vector<int>>(n + 1);
    tmp = vector<bool>(n + 1);
    visited = vector<bool>(n + 1);
    repeat(m){
        int a, b, w;
        cin >> a >> b >> w;
        g.pb({a, {b, w}});
        g2[a].pb(b);
    }
    vector<int> dist(n + 1, INT_MIN);
    dist[1] = 0;
    // auto flag = true;
    repeat(n){
        // flag = true;
        for(auto vertex : g){
            if(dist[vertex.ff] != INT_MAX){
                dist[vertex.ss.ff] = max(dist[vertex.ss.ff], dist[vertex.ff] + vertex.ss.ss);
                // if(dist[vertex.ff] + vertex.ss.ss > dist[vertex.ss.ff]){
                //     dist[vertex.ss.ff] = dist[vertex.ff] + vertex.ss.ss;
                //     // flag = false;
                // }
            }
        }
    }
    // if(!flag){
    //     cout << ":)";
    //     exit(0);
    // }
    if(!is_DAG(1)){
        cout << ":)";
        exit(0);
    }
    if(dist[n] <= INT_MIN){
        cout << ":(";
    } else{
        cout << dist[n];
    }


    endd
}