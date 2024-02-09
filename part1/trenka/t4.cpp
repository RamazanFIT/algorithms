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
    int x;
    cin >> x;
    string s;
    cin >> s;
    vector<int> massive(x);
    for(int i = 0; i < x - 1; i++){
        if(s[i] == 'W') continue;

        if((s[i] == 'R' and s[i + 1] == 'B') or (s[i] == 'B' and s[i + 1] == 'R')) {
            massive[i] = 1;
            massive[i + 1] = 1;
        }

    }
    repeat(x){
        if(massive[_] == 0 && s[_] != 'W'){
            cout << "NO" << ENDL;
            return;
        }
    }
    cout << "YES\n";
}

// BRBBW
// RBBBW
// BBBRWWRRRWBR 

// RB 
// BR
// BRBRBRBRRB
// 1111111111

// BRBRR@@BRRB
// 11111001111
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    repeat(t) solve();



    endd
}