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
vector<int> power(1e6 + 10);

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

int get_hash(string & a){
    int sum = 0;
    // int power = 1;
    for(int i = 0; i < a.size(); i++){
        sum = ((sum % mod) + (power[i] % mod) * (a[i] - 'a' + 1)) % mod;
        // sum %= mod;
        if(sum < 0){
            // sum += mod;
            // sum %= mod;
            sum = (sum + mod) % mod;
        }
        // power = (power % mod) * p;
    }
    
    // if(sum < 0){
    //         sum += mod;
    //         sum %= mod;
    // }
    return sum % mod;
    
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s;
    cin >> s;

    int q;
    cin >> q;
    
    power[0] = 1;
    power[1] = p;
    for(int i = 2; i <= s.size(); i++){
        power[i] = ((power[i - 1] % mod) * (p % mod)) % mod;
        if(power[i] < 0){
            // power[i] += mod;
            // power[i] %= mod;
            power[i] = (power[i] + mod) % mod;
        }
    }
    int ppp = binpow(p, mod - 2);

    map<pair<int, int>, int> memo;

    for(int k = 0; k < q; k++){
        int l, r;
        cin >> l >> r;
        if(memo.find(make_pair(l, r)) != memo.end()){
            cout << memo[make_pair(l, r)] << ENDL;
            continue;
        }
        string x_x = "";
        string y_y = "";
        for(int i = l - 1; i <= r - 1; i++){
            x_x += s[i];
            y_y += s[i - (l - 1)];
        }
        int x = get_hash(x_x);
        
        int y = get_hash(y_y);
        int cnt = 0;
        for(int i = y_y.size(); i <= s.size(); i++){
            // cout << x << " " << y << ENDL;
            if(x == y){
                cnt++;
            }

            y -= (s[i - y_y.size()] - 'a' + 1);
         
          
            y = ((y % mod) * ppp) % mod;

            y = ((y % mod) + (power[y_y.size() - 1] % mod) * (s[i] - 'a' + 1)) % mod;
            if(y < 0)
            y = ((y % mod) + mod) % mod;
        }
        cout << cnt << ENDL;
        memo[make_pair(l, r)] = cnt;
    }


    endd
}