#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
bool check[1000][1000];
void dfs(vector<set<int> > & g, vector<char> & color, int v){
    for(auto vertex : g[v]){
        if(color[vertex] == 'n'){
            if(color[v] == 'r'){
                color[vertex] = 'b';
            } else{
                color[vertex] = 'r';
            }
            dfs(g, color, vertex);
        }
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<char> color(n + 1, 'n');
    vector<set<int> > g(n + 1);
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        check[a][b] = 1;
        check[b][a] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(color[i] != 'n') continue;
        color[i] = 'r';
        dfs(g, color, i);
    }

    vector<int> left; // r
    vector<int> right; // b
    for(int i = 1; i <= n; i++){
        if(color[i] == 'n') continue;

        if(color[i] == 'r'){
            left.pb(i);
        } else{
            right.pb(i);
        }
    }
    for(int i = 0; i < left.size(); i++){
        for(int j = i + 1; j < left.size(); j++){
            if(check[left[i]][left[j]]){
                cout << "NO" << ENDL;
                return 0;
            }
        }
    }

    for(int i = 0; i < right.size(); i++){
        for(int j = i + 1; j < right.size(); j++){
            if(check[right[i]][right[j]]){
                cout << "NO" << ENDL;
                return 0;
            }
        }
    }

    cout << "YES" << ENDL;

    endd
}