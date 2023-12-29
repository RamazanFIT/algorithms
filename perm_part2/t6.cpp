#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

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


int C(int n, int k){
    int a = 1;
    int b = 1;
    for(int i = 1; i <= k; i++){
        b = ((b % mod) * (i % mod)) % mod;
    }
    for(int i = n; i > (n - k); i--){
        a = ((a % mod) * (i % mod)) % mod;
    }
    return ((a % mod) * binpow(b, mod - 2)) % mod;
}





signed main(){
    
    goodluck
    freopen("comb.in", "r", stdin);
    freopen("comb.out", "w", stdout);

    int n, k, c;
    cin >> n >> k >> c;
    int d = 0;
    for(int i = 0; i < k; i++){
        for(int j = d; j < n; j++){
            int f = C(n - j - 1, k - 1 - i);
            if(c >= f){
                c -= (f);
            } else{
                cout << j + 1 << " ";
                d = j + 1;
                break;
            }
        }
    }
    


    endd
}