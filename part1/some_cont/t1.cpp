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
        // hash = (hash % mod + ((some % mod) * ((s[i]  - 47ll) % mod)) % mod) % mod;
        hash = (hash % mod + multiply((some % mod), ((int(s[i])  - 47ll) % mod)) % mod) % mod;
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
    
    // goodluck
    // cout << get_hash("68") << ENDL;
    int n;
    cin >> n;
    map<string, int> mapa;
    n *= 2;
    vector<pair<string , string> > massive(n);
    set<string> sett;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        // mapa[a]++;
        // massive[i] = a;
        string hash = get_hash(a);
        // if()
        // cout << a << " " << hash << ENDL;
        massive[i] = make_pair(a, hash);
        sett.insert(a);
    }
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i < n; i++){
        if(sett.find(massive[i].second) != sett.end()){
            // cout << "Hash of string \"" << massive[i].first << "\" is " << massive[i].second << ENDL;
            sett.erase(massive[i].second);
            flag = true;
        }
        }
    }
    for(int i = 0; i < n; i++){
        if(sett.find(massive[i].second) != sett.end()){
            cout << "Hash of string \"" << massive[i].first << "\" is " << massive[i].second << ENDL;
            // sett.erase(massive[i].second);
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     string hash = get_hash(massive[i]);
    //         if(mapa[massive[i]] > 0 and mapa[hash] > 0){
                
    //             if(mapa[hash] > 0){
                   
    //                 cout << "Hash of string \"" << massive[i] << "\" is " << hash << ENDL;
                  
    //                 mapa[hash] = max(0ll, mapa[hash] - 1);
    //                 mapa[massive[i]] = max(0ll, mapa[massive[i]] - 1);
    //             } else{
    //                 mapa.erase(hash);
    //             }
    //         }
       
    // }
 


    endd
}