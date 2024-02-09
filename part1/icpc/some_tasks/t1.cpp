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
    int n, m;
    cin >> n >> m;
    n %= m;
    if(n == 0){
        cout << 0 << ENDL;
        return;
    }
    int ans = 0;
    int cnt = 0;

    while(true){
       
        if(n % m == 0){
            cout << ans << ENDL;
            return;
        }
        
        if(m <= n){
            n %= m;
        }
        ans += n;
        n *= 2;
        cnt++;
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}