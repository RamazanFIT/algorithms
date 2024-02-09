#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n, k, x;
    cin>>n>>k>>x;
    if(n < k or k - 1 > x){
        cout << -1 << ENDL;
        return;
    }
    int ans = 0;
    // int ans = ((0 + k - 1) / 2) * k;
    for(int i = 0; i < k; i++) ans+=i;
    if(k != x)
    ans += x * (n - k);
    else ans += (x - 1) * (n - k);
    cout << ans << ENDL;
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;
    cin>>n;
    while(n--) solve();
    
    


    endd
}