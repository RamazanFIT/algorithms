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
    int n, k;
    cin>>n>>k;
    if((n - (k - 1)) > 0 and (n - (k - 1)) % 2 != 0){
        cout << "YES\n";
        cout << n - (k - 1) << " ";
        for(int i = 0; i < (k - 1); i++){
            cout << 1 << " ";
        }
        cout << ENDL;
        return;
    } else if((n - (k - 1) * 2) > 0 and (n - (k - 1) * 2) % 2 == 0){
        cout << "YES\n";
        cout << n - (k - 1) * 2 << " ";
        for(int i = 0; i < (k - 1); i++){
            cout << 2 << " ";
        }
        cout << ENDL;
        return;
    } else{
        cout << "NO" << ENDL;
    }
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