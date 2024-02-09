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

int get_hash(int left, int right, string s) {
    int hash = 0;
    int some = 1;
    
    for (int i = left; i <= right; i++) {
        hash = (hash * 11 + s[i]) % mod;
    }
    
    return hash;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int ans = 0;
    int stepen = 1;

    for(int i = 0; i < s.size() - 1; i++){
        stepen = ((stepen % mod) * 11) % mod;
    }
    int left = 0;
    int x = get_hash(0, s.size() - 1, a);
    int y = get_hash(0, s.size() - 1, b);
    int z = get_hash(0, s.size() - 1, s);
    // cout << x << " " << y << " "<< stepen <<  ENDL;
    if(x == y) ans++;
    for(int i = s.size(); i < a.size(); i++){
        int tmp1 = ((x - (a[left] % mod) % mod) / 11 + ((stepen % mod) * ((a[i]) % mod)) % mod) % mod;
        int tmp2 = ((y - (b[left] % mod) % mod) / 11 + ((stepen % mod) * ((b[i]) % mod)) % mod) % mod;
        if(tmp1 == z and tmp2 == z){
            ans++;
        }
        x = tmp1;
        y = tmp2;
        left++;
    }
    cout << ans << ENDL;


    endd
}