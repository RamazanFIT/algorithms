#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;

    int l = 2023;
    bool flag = false;
    repeat(n){
        int a;
        cin >> a;
        if(l % a != 0){
            flag = true;
        }
        l /= a;
    }
    if(flag){
            cout << "NO" << ENDL;

            return;
        }
    // vector<int> ans;
    
    // for(int i = 2; i < sqrt(l) + 1; i++){

    //     while(l % i == 0){
    //         // if(ans.size() - 1 >= k){
    //         //     flag = true;
    //         //     break;
    //         // }
    //         ans.pb(i);
    //         l /= i;
    //     }

    // }
    // if(l > 1){
    //     ans.pb(l);
    // }
    // // for(auto it : ans){
    // //     cout << it << " ";
    // // }
    // // // ans.pb(l);
    // // if(ans.size() != k){
    // //     cout << "NO" << ENDL;
    // //     return;
    // // }
    // // cout << "YES" << ENDL;
    // // for(auto it : ans){
    // //     cout << it << " ";
    // // } cout << ENDL; return;
    // ans.pb(1);
    // if(!(ans.size() >= k)){
    //     cout << "NO" << ENDL;
    //     return;
    // }
    // if(k == 1){
    // cout << "YES" << ENDL;

    //     int a = 1;
    //     for(int i = 0; i < ans.size(); i++){
    //         a *= ans[i];
    //     }
    //     cout << a << ENDL;
    //     return;
    // }
    // cout << "YES" << ENDL;
    // for(int i = 0; i < k - 1; i++){
    //     cout << ans[i] << " ";
    // }
    // int a = 1;
    // for(int i = k - 1; i < ans.size(); i++){
    //     a *= ans[i];
    // }
    // cout << a << ENDL;
    cout << "YES" << ENDL;

    for(int i = 0; i < k - 1; i++){
        cout << 1 << " ";
    } cout << l << ENDL;
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;
    repeat(t) solve();
    


    endd
}