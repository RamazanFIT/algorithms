#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9 + 7;
int binmulti(int a, int b){
    if(b == 0) return 0;
    if(b == 1) return a % mod;
    int x = binmulti(a, b / 2) % mod;

    return (x % mod + x % mod + a * (b % 2)) % mod;
}



int binpow(int x, int p){
    if(p == 0) return 1ll;
    if(p == 1) return x % mod;
    int xx = binpow(x, p / 2);
    if(p % 2) return (binmulti(binmulti(xx, xx), x) + mod) % mod;
    return (binmulti(xx, xx) + mod) % mod;
}


void solution(int ccase){

    int massive[] = {-1, 1, 3, 1};

    int k;
    cin >> k;
    
    if(k % 4 == 0){
        int div = 1;

        while(k % 2 == 0){
            div *= 2;
            k /= 2;
        }

        cout << (binpow(2, div) + mod) % mod - 1 << endl;
    } else{
        cout << massive[k % 4];
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