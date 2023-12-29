#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define ll unsigned long long
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

int mod = 1e9 + 7;
int p = 31;


using namespace std;

int binpow(int a, int x){
    if(x == 0) return 1 % mod;
    if(x == 1) return a % mod;
    int ret = (binpow(a % mod, (x / 2) % mod) % mod) % mod;
    if(x % 2 == 0){
        return (ret * ret) % mod;
    } else{
        return (((ret * ret) % mod) * (a % mod)) % mod;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    string s;
    cin >> s;
    vector<int> dp(s.size() + 1);
    int d = 1;
    vector<int> poww(s.size() + 1);
    poww[0] = 1;
    for(int i = 0; i < s.size(); i++){
        dp[i + 1] = (s[i] - 'a' + 1) * (d % mod) + dp[i];
        if(dp[i + 1] < 0){
            dp[i + 1] += mod;
            dp[i + 1] %= mod;
        }
        d = ((d % mod) * p) % mod;
        if(d < 0){
            d += mod;
            d %= mod;
        }
        poww[i + 1] = d;
    }
    set<int> sett;
    for(int i = 1; i <= s.size(); i++){
        for(int j = i; j <= s.size(); j++){
            sett.insert((((dp[j] - dp[i - 1]) % mod) * (binpow(poww[i - 1], mod - 2) % mod)) % mod);
        }
    }
    cout << sett.size();
    
    


    endd
}