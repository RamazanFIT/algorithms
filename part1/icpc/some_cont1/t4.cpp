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

void solve(){
    int n;
    int k;
    cin >> n >> k;
    
    if(k >= n){
        cout << 1;
        return;
    }
    
    int tmp = n - k;

    // 10
    // 9
    // 7 
    // 5
    // 3
    // 1
    
    // 4
    // 3
    // 1

    // 5
    // 3
    // 1 2

    // 7
    // 5
    // 3
    // 1 1
    
    // if(tmp % 2 == 0){
    //     tmp--;
    //     if((tmp / 2) % 2 == 0){
    //         cout << 1;
    //     } else{
    //         cout << 2;
    //     }
    // } else{
    //     tmp -= 2;
    //     if((tmp / 2) % 2 == 0){
    //         cout << 2;
    //     } else{
    //         cout << 1;
    //     }
    // }

    // 7
    // 5
    // 3
    // 1

    // if(tmp % 2 == 0){
    //     if(k % 2 == 0){
    //         if((tmp / (k - 1)) % 2 == 0){
    //             cout << 1;
    //         } else{
    //             cout << 2;
    //         }
    //     } else{
    //         if((tmp / k) % 2 == 0){
    //             cout << 1;
    //         } else{
    //             cout << 2;
    //         }
    //     }
    // } else{
    //     if(k % 2 == 0){
    //         if((tmp / (k)) % 2 == 0){
    //             cout << 1;
    //         } else{
    //             cout << 2;
    //         }
    //     } else{
    //         if((tmp / (k - 1)) % 2 == 0){
    //             cout << 1;
    //         } else{
    //             cout << 2;
    //         }
    //     }
    // }


}


signed main(){
    
    // goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    
    


    endd
}