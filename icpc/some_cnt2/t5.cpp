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
int mod = 1000000007;
int cnt = 0;
int ans = 1;
int n, k;
vector<int> massive;
void rec(int x){
    if(cnt >= n) return;
    if(x <= 0) return;
    // cout << 1 << " ";
    ans = (ans * x) % mod;
    cnt++;
    for(int i = x - 1; i >= 0; i--){
        rec(x - i);
    }
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

   
    cin >> n >> k;
    int factorial = 1;
    rec(k);
    for(int i = 1; i <= n; i++){
        factorial = (factorial * i) % mod;
    }
    // cout << ans << ENDL;
    cout << (ans * factorial) % mod / 2;
    


    endd
}