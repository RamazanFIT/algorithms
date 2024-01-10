#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;
vector<int> factorial(2 * 1e5 + 7);
int mod = 1e9 + 7;

int binmulti(int x, int y){
    if(y == 0){
        return 0;
    } else if(y == 1){
        return x;
    }
    int xx = binmulti(x, (y / 2));
    if(y % 2 == 0){
        return (xx * 2);
    } else{
        return ((xx * 2) + x);
    }
}
int binpow(int x, int pow){
    if(pow == 0){
        return 1ll;
    } else if(pow == 1){
        return x % mod;
    }
    int xx = binpow(x % mod, (pow / 2) % mod) % mod;
    // xx *= xx;
    xx = binmulti(xx, xx);
    xx %= mod;
    if(pow % 2 == 0){
        return xx % mod;
    }
    // return (xx * x) % mod;
    return binmulti(x, xx);
}

int C(int n, int k){
    // int v = 1;
    // int niz = 1;
    // for(int i = n; i > k; i--){
    //     v = binmulti(v, i);
    // }
    // for(int i = 1; i <= (n - k); i++){
    //     niz *= i;
    // }
    // if(n - k < 105)
    // niz = factorial[n - k];
    // else niz = factorial[104];
    // return (binmulti((v), binpow(niz, mod - 2))) % mod;
    return ((n - 1) * n) / 2;
}
void solve(){
    int n;cin>>n;
    vector<int> massive(n);
    map<int, int> mapa;
    for(int i = 0; i < n; i++){
        cin >> massive[i];
        mapa[massive[i] - i]++;
    }
    int ans = 0;
    for(auto it : mapa){
        int x, y;
        x = it.first;
        y = it.second;
        if(y > 1){
            ans += C(y, 2);
        }
    }
    cout << ans << ENDL;

}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    factorial[0] = 1;
    for(int i = 1; i <= 2 * 1e5; i++){
        factorial[i] = binmulti(factorial[i - 1], i);
    }
    int t;cin>>t;repeat(t) solve();
    


    endd
}