#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


int mod = 1e9 + 7;

int multiply(int a, int b){

    if(b == 1){
        return a % mod;
    }

    if(b == 0){
        return 0ll;
    }

    int x = (multiply(a % mod, b / 2) % mod) * 2ll;
    return (x + ((b % 2) * a) % mod) % mod;

}

int binpow(int a, int x){
    if(x == 0) return 1 % mod;
    if(x == 1) return a % mod;
    int ret = (binpow(a % mod, (x / 2) % mod) % mod) % mod;
    if(x % 2 == 0){
        return multiply(ret, ret) % mod;
    } else{
        return multiply((multiply(ret, ret) % mod), a) % mod;
    }
}





string get_hash(string s){
    int hash = 0ll;
    int some = 1ll;
    for(int i = 0; i < s.size(); i++){
        // hash %= mod;
        
        // hash += ((some % mod) * ((s[i]  - 47ll) % mod)) % mod;
        hash = (hash % mod + ((some % mod) * ((s[i]  - 47ll) % mod)) % mod) % mod;
        // hash = (hash % mod + multiply((some % mod), ((int(s[i])  - 47ll) % mod)) % mod) % mod;
        if(hash < 0){
            hash += mod;
            hash %= mod;
        }
        // some = binpow(11, i);
        some = multiply(11, some);
        // some %= mod;
        if(some < 0){
            some += mod;
            some %= mod;
        }
        // some = ((some % mod) * 11ll) % mod;
        
    }
    hash %= mod;
    while(hash < 0){
        hash += mod;
        hash %= mod;
    }
    return to_string(hash % mod);
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    map<string, int> mapa;
    string w[2 * n];
    // set<string> set1;
    // set<string> set2;
    map<string , int> mapa1;
    map<string , int> mapa2;

    for(int i = 0; i < n * 2; i++){
        string a;
        cin >> a;
        mapa[a]++;
        w[i] = a;
        // set1.insert(a);
        // set2.insert(get_hash(a));
        mapa1[a]++;
        mapa2[get_hash(a)]++;
    }
    // set<string> set3;
    map<string , int> mapa3;

    for(auto it : mapa2){
        if(mapa1.find(it.first) != mapa.end()){
            mapa3[it.first] = min(mapa1[it.first], it.second);
        }
    }
    // for(auto it : mapa){
    //     cout << it.first << "  "  << it.second << ENDL;
    // }
    int cnt = 0;
    for(int i = 0; i < 2 * n; i++){
        
        string hash = get_hash(w[i]);
        if(mapa3[hash] >= 1){
            cout << "Hash of string \"" << w[i] << "\" is " << hash << ENDL;
            // mapa[hash]--;
            // mapa[w[i]]--;
            // cnt++;
            // set3.erase(hash);
            mapa3[hash]--;
        } else{
            mapa3.erase(hash);
        }
    }
    // cout << get_hash("3383080447314675044643313");

    
    


    endd
}