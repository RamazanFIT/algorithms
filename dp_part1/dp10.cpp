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
    // vector<int> numbers(n);
    // for(int i = 0; i < n; i++) cin >> numbers[i];

    vector<vector <int> >  dp(n + 1, vector<int>(n + 1));
    vector<int> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; i++){
        dp[1][i] = 1;
        prefix_sum[1] += dp[1][i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // dp[i][j] += dp[max(0, i - j)][j];
            dp[i][j] = prefix_sum[max(0, i - j)];
            prefix_sum[i] += prefix_sum[max(0, i - j)];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << " ";
        } cout << ENDL;
    }
    


    endd
}