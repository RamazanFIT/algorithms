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
#define int ll
#define matrix pair<pair<int, int>, pair<int, int>>
#define add(x, y, a, b) {{x, y}, {a, b}}
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
const int mod = 1000000007;

matrix multiply(matrix a, matrix b){
    return add(((a.ff.ff  % mod) * (b.ff.ff % mod) % mod + (a.ff.ss % mod) * (b.ss.ff % mod) % mod)  % mod,
                ((a.ff.ff % mod) * (b.ff.ss % mod) % mod + (a.ff.ss % mod) * (b.ss.ss % mod) % mod)  % mod,
                ((a.ss.ff % mod) * (b.ff.ff % mod) % mod + (a.ss.ss  % mod) * b.ss.ff % mod)  % mod,
                ((a.ss.ff % mod) * (b.ff.ss % mod) % mod + (a.ss.ss % mod) * (b.ss.ss % mod) % mod)  % mod
                );
}

matrix binpow(matrix a, int p){
    if(p == 0){
        return add(1, 1, 1, 1);
    } else if(p == 1) return a;
    matrix x = binpow(a, (p / 2));
    if(p % 2 == 0){
        return multiply(x, x);
    } else return multiply(multiply(x, x), a);
}

void solve(int ccase){
    int n;
    cin >> n;
    int a = binpow(add(0, 1, 1, 1), 2 * n - 1).ss.ss;
    int b = binpow(add(0, 1, 1, 1), 2 * n).ss.ss;
    cout << ((a % mod) * (b % mod))  % mod << ENDL;
    // if(n == 0) cout << 0;
    // else
    // cout << binpow(add(0, 1, 1, 1), n - 1).first.first << " " << binpow(add(0, 1, 1, 1), n - 1).first.second << ENDL;
    // cout << binpow(add(0, 1, 1, 1), n - 1).second.first << " " << binpow(add(0, 1, 1, 1), n - 1).second.second;
    // cout << binpow(add(0, 1, 1, 1), n - 1).second.second;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}