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
vector<int> power(105);
string get_hash(string s){
    int hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash = ((hash % mod) + ((power[i] % mod) * (s[i]  - 47)) % mod) % mod;
        while(hash < 0){
            hash += mod;
            hash %= mod;
        }
        
    }
    while(hash < 0){
        hash += mod;
        hash %= mod;
    }
    hash %= mod;
    // return to_string(hash);
    string tmp = "";
    while(hash > 0){
        tmp += char('0' + hash % 10);
        hash /= 10;
    }
    reverse(all(tmp));
    return tmp;
}

int binpow(int x, int power){
    if(power == 1) return x % mod;
    else if(power == 0) return 1ull;
    int xx = binpow(x % mod, power / 2) % mod;
    if(power % 2 == 0){
        return (xx * xx) % mod;
    } else{
        return (((xx * xx) % mod) * (x % mod)) % mod;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    for(int i = 0; i <= 104; i++){
        power[i] = binpow(11, i);
        while(power[i] < 0){
            power[i] += mod;
            power[i] %= mod;
        }
    }
    // for(int i = 0; i < 10; i++){
    //     cout << power[i] << " ";
    // } cout << endl;
    int n;
    cin >> n;
    map<string, int> mapa;
    n *= 2;
    vector<string> massive(n);
    for(int i = 0; i < n; i++){
        string a;

        cin >> a;
        mapa[a]++;
        massive[i] = a;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        string hash = get_hash(massive[i]);
        if((mapa.find(hash) != mapa.end()) and mapa[hash] >= 1){
            cout << "Hash of string \"" << massive[i] << "\" is " << hash << ENDL;
        }
    }

    
    
    

    endd
}