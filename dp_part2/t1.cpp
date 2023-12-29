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
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);

    int n;
    cin >> n;
    int dp[n + 2];
    int w[n];
    for(int i = 0; i < n; i++) cin >> w[i];
    dp[0] = 0;
    dp[1] = w[0];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2]) + w[i - 1];
    }
    cout << dp[n] << ENDL;
    


    endd
}