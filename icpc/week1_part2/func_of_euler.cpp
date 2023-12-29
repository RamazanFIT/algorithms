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
int dp[15000];
int w[15000];

void solve(){
    int n;
    cin >> n;
    
    cout << dp[n] * dp[n] << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    for(int i = 2; i <= 10000; i++){
        int totient = 1;
        int k = i;
        int c = sqrt(i) + 1;
        for(int j = 2; j <= c; j++){
            if((k % j) == 0){
                int number = 1;
                while(k % j == 0){
                    number *= j;
                    k /= j;
                }
                totient *= (number - number / j);
            }
        }
        if(k > 1){
            totient *= (k - 1);
        }
        w[i] = totient;
    }
    w[1] = 1;
    dp[1] = 1;
    for(int i = 2; i < 10005; i++){
        dp[i] = dp[i - 1] + w[i];
    }
    

    int n;
    cin >> n;
    while(n--) solve();
    // cout << w[15];
    // for(int i = 1; i <= 4; i++) cout << w[i] << " ";

    endd
}