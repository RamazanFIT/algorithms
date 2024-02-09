#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int mod = 1e9 + 7;
int p = 103;


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




int get_hash(string a){
    int sum = 0;
    int power = 1;
    for(int i = 0; i < a.size(); i++){
        sum += ((power % mod) * (a[i] - 'a' + 1)) % mod;
        sum %= mod;
        if(sum < 0){
            sum += mod;
            sum %= mod;
        }
        power = (power % mod) * p;
    }
    // return ((sum % mod) + mod) % mod;
    if(sum < 0){
            sum += mod;
            sum %= mod;
    }
    return sum % mod;
    
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    string c;
    cin >> c;
    string a_a;
    string b_b;
    for(int i = 0; i < min(c.size(), a.size()); i++){
        a_a += a[i];
    }
    for(int i = 0; i < min(c.size(), b.size()); i++){
        b_b += b[i];
    }
    int hash_a = get_hash(a_a);
    int hash_b = get_hash(b_b);
    int hash_c = get_hash(c);
    int z = 1;
    for(int i = 0; i < c.size() - 1; i++){
        z = (p % mod) * (z % mod);
    }
    // cout << z << ENDL;
    int ans = 0;
    int ppp = binpow(p, mod - 2);
    for(int i = c.size(); i <= min(a.size(), b.size()); i++){
        if(hash_a == hash_c and hash_b == hash_c){
            ans++;
        }
        // cout << hash_a << " " << hash_b << " " << hash_c << endl;
        hash_a -= (a[i - c.size()] - 'a' + 1);
        hash_b -= (b[i - c.size()] - 'a' + 1);
        // hash_a /= p;
        // hash_b /= p;
        hash_a = ((hash_a % mod) * ppp) % mod;
        hash_b = ((hash_b % mod) * ppp) % mod;

        hash_a = ((hash_a % mod) + (z % mod) * (a[i] - 'a' + 1)) % mod;
        if(hash_a < 0)
        hash_a = ((hash_a % mod) + mod) % mod;
        hash_b = ((hash_b % mod) + (z % mod) * (b[i] - 'a' + 1)) % mod;
        if(hash_b < 0)
        hash_b = ((hash_b % mod) + mod) % mod;
        
    }
    cout << ans;


    
    


    endd
}