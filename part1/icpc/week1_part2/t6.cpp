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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int ans = 0;
    if(n == 1){
        cout << 1 << ENDL;
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) ans++;
    }
    ans *= 2;
    int k = int(sqrt(n));
    if(n == k * k){
        ans--;
    }
    cout << ans << ENDL;
    

    
    


    endd
}