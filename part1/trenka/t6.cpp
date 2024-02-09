// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;

#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = int;
using namespace std;

ll pow1(ll x, int p){
    ll l = 1;
    repeat(p) l = (l << 1);
    return l;
}
int someX = pow1(2, 31);

void solve(){
    int n, k;cin >> n >> k;
    vector<int> massive(n);
    vector<int> p(65);

    repeat(n) {
        cin >> massive[_];
        int x = massive[_];
        int i = 0;
        while(x > 0){
            p[i] += (x % 2);
            i++;
            x/=2;
        }
    }
  
    // 60 
    // 12 
    // 60 - 12 = 48 
    for(int i = 30; i >= 0; i--){
        if((n - p[i]) <= k){
            k -= (n - p[i]);
            p[i] = 1;
        } else{
            p[i] = 0;
        }
        
    }
    int ans = 0;
    for(int i = 0; i <= 30; i++){
        if(p[i])
        ans += pow1(2, i);
        
    }

    cout << ans << ENDL;
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t)solve();
    


    endd
}