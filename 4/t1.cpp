#include <bits/stdc++.h>

using namespace std;
#define ENDL endl
#define int long long
int mod = 1e9 + 7;

int binmulti(int a, int b){
    if(b == 0) return 0;
    if(b == 1) return a % mod;
    int x = binmulti(a % mod, b/2);
    return (x % mod + x % mod  + (b % 2) * a % mod) % mod;
}


int binpow(int x, int p){
    if(p==0) return 1;
    if(p==1) return x % mod;

    int xx = binpow(x, p / 2) % mod;

    if(p % 2 != 0) return binmulti(binmulti(xx, xx), x) % mod;
    else return binmulti(xx, xx) % mod;
}

void solution(int ccase){

    int a, b, c;
    while(cin >> a >> b >> c){
        mod = c;
        // cout << binpow(a, b) << ENDL;

        int ans = binpow(a, b);

        while(ans < 0){
            ans += c;
            ans %= c;
        }
        cout << ans << ENDL;
    }



}


signed main(){

    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solution(i);
    }
    
    return 0;
}