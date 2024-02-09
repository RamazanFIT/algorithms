#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll =  long long;
using namespace std;

signed main(){
    
    goodluck
    freopen("aztec.in", "r", stdin);
    freopen("aztec.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> dp(1e6 + 1);
    
    dp[1] = 1;
    dp[2] = 5;
    vector<int> ans(1e6);
    if(n == 1){
        cout << 1;
        endd
    }
    if(n == 0){
        cout << 0;
        endd
    }
    ans[1] = dp[1];
    ans[2] = ans[1] + dp[2];
    for(int i = 3; i <= 1e6; i++){
        dp[i] = dp[i - 1] + 4 * (i - 1);
        ans[i] = ans[i - 1] + dp[i];
        // dp[i] = 2 * i + 2 * (i - 2) + dp[i - 1];
    }
    
    for(int i = 1; i <= 1e6; i++){
        if(n < ans[i]){
            // cout << i << ENDL;
            // if(n - dp[i] == 0){
            //     cout << i;
            // } else{
                cout << i - 1;
            // }
            return 0;
        }
    }
    // for(int i = 1; i < 10; i++) cout << ans[i] << " ";
    // for(int i = 1; i <= 1e6; i++){
    //     dp[i] = dp[i - 1] + i * i;
    //     // if(dp[i])
    // }
    // int left = 0;
    // int right = 1e6 + 1;
    // while(right - left > 1){
    //     int mid = (right + left) / 2;
    //     if(ans[mid] < n){
    //         left = mid;
    //     } else{
    //          right = mid;
    //     }
    // }
    // cout << left << endl;
    endd
}