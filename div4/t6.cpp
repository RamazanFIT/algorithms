#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int long long
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


void solve(){
    int n;
    cin>>n;
    int x;
    cin>>x;

    vector<int> massive(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> massive[i];
      
    }
    if(n == 1 and x == 1){
        if(massive[0] == 1){
            cout << 2 << ENDL;
            return;
        }
    }
    sort(all(massive));
    vector<int> dp(n);
    dp[0] = massive[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + massive[i];
    }
    int ans = dp[0];
    for(int i = 1; i < n; i++){
        if(massive[i] * i - dp[i - 1] <= x){
            ans = max(massive[i], ans);
        } else{
            int index = massive[i];
            while(index > massive[i - 1]){
                if(index * i - dp[i - 1] <= x){
                    ans = max(ans, index);
                }
                index--;
            }
        }
    }
    // int index = n;
    // while(index <= x + 1000){
    //     if(index * n - dp[n - 1] <= x){
    //         ans = max(ans, index);
    //     }
    //     index++;
    // }
    int left = 0;
    int right = INT_MAX;
    if(massive[n - 1] < x)
    while(right - left > 1){
        int mid = (left + right) / 2;
        // cout << right << ENDL;
        if((mid * n - dp[n - 1]) <= x){
            ans = max(ans, mid);
            left = mid;
            // cout << dp[n - 1] << ENDL;
            // cout << (mid * n - dp[n - 1]) << ENDL;
            // cout << mid << ENDL;
        } else{
            right = mid;
        }
    }

    cout << ans << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    while(n--){
        solve();
    }
    


    endd
}