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
    int n;
    cin>>n;
    int min_ = 9;
    int w[n];
    for(int i = 0; i < n; i++){
        cin >> w[i];
        min_ = min(min_, w[i]);
    }
    for(int i = 0; i < n; i++){
        if(w[i] == min_){
            w[i]++;
            break;
        }
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans *= w[i];
    }
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
