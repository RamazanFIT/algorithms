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
int p = 107;
int p2 = 87;
vector<int> power(2000 + 10);
vector<int> power2(2000 + 10);


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

pair<int, int> get_hash(string & a){
    int sum = 0;
    int sum2 = 0;

    for(int i = 0; i < a.size(); i++){
        sum = ((sum % mod) + ((power[i] % mod) * (a[i] - 'a' + 1)) % mod) % mod;
        sum2 = ((sum2 % mod) + ((power2[i] % mod) * (a[i] - 'a' + 1)) % mod) % mod;
        if(sum < 0){
            sum += mod;
            sum %= mod;
        }
        if(sum2 < 0){
            sum2 += mod;
            sum2 %= mod;
        }
    }
    if(sum < 0){
        sum += mod;
        sum %= mod;
    }
    if(sum2 < 0){
        sum2 += mod;
        sum2 %= mod;
    }
    return make_pair(sum % mod, sum2 % mod); 
    
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    set<pair<int, int> > st;
    
    
    string s;
    cin >> s;
    
    power[0] = 1;
    power[1] = p;

    power2[0] = 1;
    power2[1] = p2;

    for(int i = 2; i < s.size() + 3; i++){
        power[i] = ((power[i - 1] % mod) * (p % mod)) % mod;
        if(power[i] < 0){
            power[i] += mod;
            power[i] %= mod;
        }

        power2[i] = ((power2[i - 1] % mod) * (p2 % mod)) % mod;
        if(power2[i] < 0){
            power2[i] += mod;
            power2[i] %= mod;
        }
    }
    int ppp = 224299067;
    int ppp2 = 252873565;

    for(int i = 1; i <= s.size(); i++){
        string x_x = "";
        for(int j = 0; j < i; j++){
            x_x += s[j];
        }
        pair<int, int> xxxxxx = get_hash(x_x);
        int x = xxxxxx.first;
        int x2 = xxxxxx.second;
        for(int j = i; j <= s.size(); j++){
            // cout << x << ENDL;
            if(st.find(make_pair(x, x2)) == st.end())
            st.insert(make_pair(x, x2));
            x -= (s[j - i] - 'a' + 1);
            x = ((x % mod) * ppp) % mod;
            x = ((x % mod) + (power[i - 1] % mod) * (s[j] - 'a' + 1)) % mod;
            if(x < 0)
            x = ((x % mod) + mod) % mod;

            x2 -= (s[j - i] - 'a' + 1);
            x2 = ((x2 % mod) * ppp2) % mod;
            x2 = ((x2 % mod) + (power2[i - 1] % mod) * (s[j] - 'a' + 1)) % mod;
            if(x2 < 0)
            x2 = ((x2 % mod) + mod) % mod;
        }
    }
    cout << st.size();

    
    


    endd
}