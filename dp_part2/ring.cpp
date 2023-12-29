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
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    vector<int> dp(n + 1, INT_MAX);
    for(int i = 1; i <= n; i++){
        int index = -1;
        for(int j = 1; j < massive.size() - 1; j++){
            // dp[i] = min(dp[i], massive[j - 1] * massive[j] * massive[j + 1]);
            int c = massive[j - 1] * massive[j] * massive[j + 1];
            if(dp[i] > c){
                dp[i] = c;
                index = j;
            }
        }
        if(index != -1){
            massive.erase(massive.begin() + index);
        }
    }
    // cout << dp[]
    


    endd
}