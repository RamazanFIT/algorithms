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

vector<bool> w(2000001, 0);

void sieve(){
    for(int i = 2; i < sqrt(2000001); i++){
        if(!w[i]){
            for(int j = i * i; j < 2000001; j += i){
                w[j] = true;
            }
        }
    }
}

void solve(){
    int left, right;
    cin >> left >> right;

    int ans = 0;
    for(int i = 2; i < sqrt(right) + 1; i++){
        if(!w[i]) //max(left / i, i)
        for(int j = i * i; j <= right; j *= i){
            if((j >= left) and (j <= right)){
                ans++;
                // cout << j << " ";
            }
        }   
    }
    cout << ans << ENDL;

}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    sieve();
    int n;
    cin>>n;
    while(n--) solve();


    endd
}