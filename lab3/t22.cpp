#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

bool check(vector<int> & dp, vector<int> & massive, int k, int x){
    
    for(int i = 0; i <= dp.size() - x; i++){
        if(dp[i + x - 1] - dp[i] + massive[i] >= k){
            return true;
        }
    }
    return false;
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> massive(n);
    vector<int> dp(n);
    int sum = 0;
    cin >> massive[0];
    dp[0] = massive[0];
    for(int i = 1; i < n; i++){
        cin >> massive[i];
        dp[i] = dp[i - 1] + massive[i];
    }
    
    int ans = n;

    int left = -1;
    int right = n;
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(check(dp, massive, k, mid)){
            ans = min(ans, mid);
            right = mid;
        } else{
            
            left = mid;
        }
        // cout << mid << ENDL;
    }
    cout << ans << ENDL;
    
    
    


    endd
}