#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> massive[i];
    }

    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            int last_pos = j + i - 1;
            dp[j][last_pos] = INT_MAX;
            for(int k = j + 1; k < last_pos; k++){
                dp[j][last_pos] = min(dp[j][last_pos], dp[j][k] + dp[k][last_pos] + massive[j] * massive[k] * massive[last_pos]);
            }
        }
    }
    cout << dp[1][n] << ENDL;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     } cout << ENDL;
    // }
    
    
    


    endd
}