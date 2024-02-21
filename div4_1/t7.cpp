// Bismillah 
// لا إله إلا الله محمد رسول الله
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

void solve(int ccase){
    vector<int> m(1);
    vector<int> m1(1);
    m[100] = 12;
    // cout << m[100];
    for(int i = 0; i < 1000; i++){
        m[i] = i;
    }
    // print(m);
    for(int i = 0; i < 1000; i++){
        // m[i] = i;
        cout << m[i] << " ";
    }
    cout << ENDL;
    cout <<m1[0];
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}