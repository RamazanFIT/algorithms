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

string get_hash(string s){
    int hash = 0;
    int some = 1;
    for(int i = 0; i < s.size(); i++){
        hash += (some * (s[i]  - 47)) % mod;
        some *= 11;
        some %= mod;
    }
    hash %= mod;
    return to_string(hash);
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

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
    for(int i = 0; i < n; i++){
        string hash = get_hash(massive[i]);
        if(mapa[hash]){
            cout << "Hash of string \"" << massive[i] << "\" is " << hash << ENDL;
            mapa[hash] = max(0ull, mapa[hash] - 1);
        }
    }
    
    

    endd
}