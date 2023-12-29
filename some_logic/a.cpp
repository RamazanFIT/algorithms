#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int L = 2e6 + 5;
vector<int> f_euler(L);
vector<int> deep(L);
int mod = 1e9 + 7;
int binpow(int a, int p){
    if(p == 0) return 1 % mod;
    else if(p == 1) return a % mod;
    int x = binpow(a, p / 2);
    if(p % 2 == 0){
        return (x * x) % mod;
    } else return (x * x * a) % mod;
}

int f(int a){
    int ans = 0;
    int b = a;
    for(int i = 2; i < sqrt(a); i++){
        if(b % i == 0){
            int cnt = 0;
            while(b % i == 0){
                cnt++;
                b /= i;
            }
            ans += binpow(i, cnt);
        }
    }
    if(b > 1){
        ans += b - 1;
    }
    return ans;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    for(int i = 1; i < L; i++){
        f_euler = f(i);
    }
    


    endd
}