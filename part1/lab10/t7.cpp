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


void dfs(vector<vector<int > > & w, int i, int j){
    w[i][j] = 0;
    if(w[i + 1][j]){
        dfs(w, i + 1, j);
    }
    if(w[i - 1][j]){
        dfs(w, i - 1, j);
        
    }
    if(w[i][j + 1]){
        dfs(w, i, j + 1);
        
    }
    if(w[i][j - 1]){
        dfs(w, i, j - 1);
    }
    return;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout); 

    int n, m;
    cin >> n >> m;
    
    vector<vector<int > > w(n + 2, vector<int>(m + 2));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char a;
            cin >> a;
            w[i][j] = a - '0';
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(w[i][j]){
                dfs(w, i, j);
                cnt++;
            }
        }
    }

    cout << cnt << ENDL;

    endd
}