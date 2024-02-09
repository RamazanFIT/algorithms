#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


// bool flag = true;

// void check(vector<vector<int> > & g, int v, int start, vector<bool> & b){
//     b[v] = true;
//     if(!flag) return;
    
//     for(auto vertex : g[v]){

//         if(vertex == start){
//             flag = false;
//             return;
//         }
//         if(b[vertex]) continue;
//         if(!flag) return;
//         check(g, vertex, start, b);
//         if(!flag) return;
//     }
    
// }


// bool DAG(vector<vector<int> > & g){
    
//     int cnt = 0;
//     int c = 0;
//     vector<bool> b(g.size());
//     for(int i = 1; i < g.size(); i++){
//         if(b[i]) continue;
//         check(g, i, i, b);
//         if(!flag){
//             flag = true;
//             return false;
//         }
//     }
//     flag = true;
//     return true;
// }

bool check(vector<vector<int>> & g, int v, vector<bool> &stacking, vector<bool> &b){
    b[v] = true;
    stacking[v] = true;
    for(auto vertex : g[v]){
        if(b[vertex]){
            if(stacking[vertex]){
                return true;
            }
        } else{
            if(check(g, vertex, stacking, b)){
                return true;
            }
        }
    }
    stacking[v] = false;
    return false;
}
bool DAG(vector<vector<int>> & g){
    vector<bool> b(g.size());
    vector<bool> stacking(g.size());
    for(int i = 1; i < g.size(); i++){
        if(b[i]) continue;
        if(check(g, i, stacking, b)){

            return false;
        }
    }
    return true;
}
vector<int> ans;
// unordered_set<int> visited;
vector<bool> visited(1e5 + 7);
void top_sort(vector<vector<int> > & g, int v){
    if(visited[v]) return;
    
    for(auto vertex : g[v]){
        top_sort(g, vertex);
        
    }
    ans.pb(v);
    visited[v] = true;
    
    
    return;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >>  a >> b;
        g[a].pb(b);
    }
    
    if(!DAG(g)){
        cout << "Impossible";
        return 0;
    }

    for(int v = 1; v <= n; v++){
        if(visited[v]) continue;
        top_sort(g, v);

    }
    cout << "Possible" << ENDL;
    reverse(all(ans));
    for(auto it : ans){
        cout << it << " ";
    }

    endd
}