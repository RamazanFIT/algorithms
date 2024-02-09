// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    // map<char, set<char>> mapa1;
    // map<char, set<char>> mapa2;
    map<char, int> mapa1;
    map<char, int> mapa2;
    map<pair<char, char>, int> mapa;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        char a, b;
        cin >> a >> b;
        ans += mapa1[a] - mapa[{a, b}];
        ans += mapa2[b] - mapa[{a, b}];
        mapa1[a]++;
        mapa2[b]++;
        mapa[{a, b}]++;
    }
    cout << ans << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;cin >> n; repeat(n) solve();  
    


    endd
}

// aa
// bb
// cc
// ac
// ca
// bb
// aa
// 1 + 1 + 1 + 1 + 0 + 0 + 1 + 1 = 6
// a : a, c
// b : b 
// c : c a 

// a : a, c
// b : b 
// c : c a 
// jf jk 

// jf
// jf
// jk
// jk
// jk

// j : f k 


// f: j
// k: j