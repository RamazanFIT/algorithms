// Bismillah 
// لا إله إلا الله محمد رسول الله
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define int ll
#define vvi vector<vector<int>>
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int mod = 1e9 + 7;
int multi(int x, int y){
    if(y == 0) return 0;
    else if(y == 1) return x % mod;
    int xx = multi(x, y / 2);
    return (y % 2) * (x % mod) + (xx % mod) * 2;
}

int binpow(int a, int p){
    if(p == 0) return 1;
    else if(p == 1) return a % mod;
    int x = binpow(a, p / 2) % mod;
    if(p % 2){
        int y = multi(x, x);
        return multi(a, y);
    } else {
        int y = multi(x, x);
        return y;
    }
}

void solve(int ccase){
    // for(int i = mod / 2; i <= mod; i++){

    //     if(multi(i, i) % mod == 5){
    //         cout << i << " ";
    //         return;
    //     }
    // }
    int x = 1000000006;
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}