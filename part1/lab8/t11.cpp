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

int mod = 1e9;
int p = 107;
vector<int> power(2000 + 10);

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
    for(int i = 0; i < a.size(); i++){
        sum += ((power[i] % mod) * (a[i] - 'a' + 1)) % mod;
        sum %= mod;
        if(sum < 0){
            sum += mod;
            sum %= mod;
        }
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

    set<int> st;

    string s;
    cin >> s;
    
    power[0] = 1;
    power[1] = p;
    for(int i = 2; i < s.size() + 3; i++){
        // power[i] = ((power[i - 1] % mod) * (p % mod)) % mod;
        // if(power[i] < 0){
        //     power[i] += mod;
        //     power[i] %= mod;
        // }
        power[i] = binpow(p, i);
    }
    int ppp = binpow(p, mod - 2);

    for(int i = 1; i <= s.size(); i++){
        string x_x = "";
        for(int j = 0; j < i; j++){
            x_x += s[j];
        }
        int x = get_hash(x_x);
        for(int j = i; j <= s.size(); j++){
            // cout << x << ENDL;
            st.insert(x);
            x -= (s[j - i] - 'a' + 1);
            x = ((x % mod) * ppp) % mod;
            x = ((x % mod) + (power[i - 1] % mod) * (s[j] - 'a' + 1)) % mod;
            if(x < 0)
            x = ((x % mod) + mod) % mod;
        }
    }
    cout << st.size();

    
    


    endd
}