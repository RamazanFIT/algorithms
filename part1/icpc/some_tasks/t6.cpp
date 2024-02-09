#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int a[1000000];
int dp[1000000];
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dp[2] = a[2] - a[1];
    dp[3] = a[3] - a[1];
    for(int i = 4; i <= n; i++){
        dp[i] = min(dp[i - 2], dp[i - 1]) + a[i] - a[i - 1];
    }
    cout << dp[n] << ENDL;
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }

    endd
}