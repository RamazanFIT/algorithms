#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int dp[100][100];

signed main(){
    
    goodluck
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);

    int n = 8, m = 8;
    
    int w[n + 1][m + 1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> w[i][j];
        }
    }
  
    for(int i = n - 1; i >= 1; i--){
        dp[i][1] = dp[i + 1][1] + w[i - 1][0];
    }
    for(int i = 2; i <= m; i++){
        dp[n][i] = dp[n][i - 1] + w[n - 1][i - 1];
    }
    
    for(int i = n - 1; i >= 1; i--){
        for(int j = 2; j <= m; j++){
            dp[i][j] = min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i][j - 1])) + w[i - 1][j - 1];
        }
    }
    cout << dp[1][m] << ENDL;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }cout << ENDL;
    // }


    endd
}