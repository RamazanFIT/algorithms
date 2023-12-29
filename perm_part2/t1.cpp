#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

int C(int n, int k){
    int a = 1;
    int b = 1;
    for(int i = 1; i <= k; i++) b *= i;
    for(int i = n; i > (n - k); i--){
        a *= i;
    }
    return a / b;
}
int mod = 1e9 + 7;
int binpow(int x, int power){
    if(power == 1) return x % mod;
    else if(power == 0) return 0ull;
    int xx = binpow(x % mod, power / 2) % mod;
    if(power % 2 == 0){
        return (xx * xx) % mod;
    } else{
        return (((xx * xx) % mod) * (x % mod)) % mod;
    }
}

signed main(){
    
    // cout << 1 << ENDL;
    // int k = 2;
    // cout << k;
    // cout << int('a') << ENDL;
    // cout << (long long)('v');
    cout << C(10, 2) << ENDL;
    cout << binpow(10, 2);
}