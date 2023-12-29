#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> w(n + 1, vector<int>(n + 1, INT_MAX));
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int cost;cin >> cost;
        w[a][b] = cost;
        w[b][a] = cost;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    cout << w[1][n];
    // O(n * n * n)
    


    endd
}