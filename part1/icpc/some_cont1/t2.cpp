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

int dp[320000];

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    
    cout << ans << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    dp[1] = 1;
    int sum = 1;
    for(int i = 2; i < 300002; i++){
        sum += i;
        dp[i] = dp[i - 1] + sum;
    }
    for(int i = 1; i < 10; i++) cout << dp[i] << " ";
    int n;  
    cin >> n;
    while(n--) solve();
    


    endd
}