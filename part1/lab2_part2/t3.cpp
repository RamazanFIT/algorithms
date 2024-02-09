#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<int> ans;
    ans.push_back(n);
    for(int i = 0; i < n; i++){
        int k = (1 << i);
        if(k >= n) break;
        if(k & n){
            n -= k;
            ans.push_back(n);
        }
    }
    while(n > 1){
        ans.push_back(n / 2);
        n /= 2;
    }
    cout << ans.size() << ENDL;
    for(auto it : ans){
        cout << it << " ";
    }
    cout << ENDL;

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