#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

// int gcd(int a, int b){
//     if(a == 0){
//         return b;
//     } else{
//         return gcd(b % a, a);
//     }
// }

int w[1000];
int dp[1000];

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int a, b;
    cin >> a >> b;
    // int c = gcd(a, b);
    // cout << c << ENDL;
    int c = sqrt(max(a, b)) + 1;
    int index = 0;
    for(int i = 1; i < c; i++){
        if(a % i == 0 and b % i == 0){
            w[i] = 1;
            int d, k;
            d = a / i;
            k = b / i;
            index = max(index, i);
            if(a % d == 0 and b % d == 0){
                w[d] = 1;
                index = max(d, i);
            } 
            if(a % k == 0 and b % k == 0){
                w[k] = 1;
                index = max(k, i);
            }
        }
    }
    for(int i = 1; i <= index; i++){
        dp[i] = dp[i - 1] + w[i];
    }
    // int q;
    // cin >> q;
    // while(q--){
    //     int l, r;
    //     cin >> l >> r;
    //     int ans = -1;
    //     while(r - l > 1){
    //         int mid = (r + l) / 2;
    //         if(dp[mid] >= 1){
    //             ans = mid;
    //             r = mid;
    //         } else{
    //             l = mid;
    //         }
    //     }
    //     cout << ans << ENDL;
    // }
    
    for(int i = 1; i <= 10; i++){
        cout << dp[i] << " ";
    }

    


    endd
}