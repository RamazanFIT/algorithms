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

    string s;
    cin >> s;

    int n;
    cin >> n;
    vector<int> massive(s.size());

    for(int q = 0; q < n; q++){
        string a;
        cin >> a;
        string b_b;
        for(int i = 0; i < a.size(); i++){
            b_b += s[i];
        }
        int hash_b = get_hash(b_b);
        int hash_a = get_hash(a);
        int z = 1;
        for(int i = 0; i < a.size() - 1; i++){
            z = (p % mod) * (z % mod);
        }
        int ppp = binpow(p, mod - 2);
        for(int i = a.size(); i <= s.size(); i++){
            // cout << hash_b << " " << hash_a << ENDL;
            if(hash_b == hash_a){
               for(int j = i - a.size(); j < i; j++){

                    massive[j]++;
                }
            }
         
            hash_b -= (s[i - a.size()] - 'a' + 1);
         
          
            hash_b = ((hash_b % mod) * ppp) % mod;

            hash_b = ((hash_b % mod) + (z % mod) * (s[i] - 'a' + 1)) % mod;
            if(hash_b < 0)
            hash_b = ((hash_b % mod) + mod) % mod;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(!massive[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    // for(int i = 0; i < s.size(); i++){
    //     cout << massive[i] << " ";
    // }

    endd
}