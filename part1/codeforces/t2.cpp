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
    int n, m;
    cin>>n>>m;
    int max_ = 0;
    vector<int> massive1(n);
    vector<int> massive2(m);
    for(int i = 0; i < n; i++){
        cin >> massive1[i];
        max_ ^= massive1[i];
    }
    int target = 0;
    for(int i = 0; i < m; i++){
        cin >> massive2[i];
        target |= massive2[i];
    }
    for(int i = 0; i < n; i++){
        massive1[i] |= target;
    }
    int min1 = 0;
    for(int i = 0; i < n; i++){
        min1 ^= massive1[i];
    }
    cout << min(min1, max_) << " " << max(min1, max_) << ENDL;

    

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