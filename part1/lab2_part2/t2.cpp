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
    int n, x, y;
    cin>>n>>x>>y;
    
    int sum1 = 0;
    int sum2 = 0;

    // sum1 = ((n + n - x + 1) * n) / (2 * x);
    // sum2 = 1 + n
    // sum1 = ((n + n - x + 1 + (n / (x * y))) * n) / (2 * x);
    // sum1 = ((n + n - x + 1 + int(n / (x * y))) / 2) * (int(n / x) - int(n / (x * y)));
    // sum2 = ((1 + int(n / y) - int(n / (x * y))) / 2) * (int(n / y) - int(n / (x * y)));
    // sum1 = ((2 * n * x * y + x * y - n * y + n) * (n * y - n)) / (2 * x * x * y * y);
    // sum2 = ((2 * n * x * y + x * y - n * y + n) * (n * y - n));
    // sum2 = ((x * y + n * x - n) * (n * x - n));
    // cout << sum1 - sum2 << ENDL;
    cout << (((2 * n * x * y + x * y - n * y + n) * (n * y - n)) - ((x * y + n * x - n) * (n * x - n))) / (2 * x * x * y * y);
    

}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}