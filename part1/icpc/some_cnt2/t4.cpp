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
int dp[1002][1002];
int massive[1002][1002];

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    int m;
    cin >> n >> m;
    int w[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> w[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        dp[i][1] = w[i][1];
        for(int j = 2; j <= m; j++){
            dp[i][j] = dp[i][j - 1] + w[i][j]; 
        }
    }
    for(int i = 1; i <= m; i++){
        massive[1][i] = dp[1][i];
        for(int j = 2; j <= n; j++){
            massive[j][i] = massive[j - 1][i] + dp[j][i];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int z = min(b, d);
        int x = max(a, c);
        int y = max(b, d);
        int f = min(a, c);
        cout << massive[x][y] - massive[f - 1][y] - (massive[x][z - 1] - massive[f - 1][z - 1]) << ENDL;
        // cout << massive[max(a, c)][max(b, d)] - massive[min(a, c)][max(b, d)] - (massive[max(a, c)][min(b, d)] - massive[min(a, c)][min(b, d)]) << ENDL;
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << massive[i][j] << " ";
    //     } cout << ENDL;
    // }
    
    
    


    endd
}