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
vector<vector<int>> g;
vector<bool> visited;
int cnt = 0;
bool flag = true;
void dfs(int v, int parent){
    visited[v] = true;

    for(auto vertex : g[v]){
        if(parent == vertex) continue;
        if(visited[vertex]){

            flag = false;
            return;

        } else{
            dfs(vertex, v);
        }
    }

}
bool is_AG(){
    for(int i = 1; i < visited.size(); i++){
        if(!visited[i]){
            dfs(i, i);
            cnt++;
        }
    }
    if(flag){
        return true;
    }
    return false;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    while(cin >> n){

        g = vector<vector<int>>(n + 1);
        visited = vector<bool>(n + 1);
        flag = true;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int a;
                cin >> a;
                if(a == 1){
                    g[i].pb(j);
                }
            }
        }
        if(is_AG() and cnt == 1){
            cout << "YES" << ENDL;
        } else{
            cout << "NO" << ENDL;
        }
    }
    


    endd
}