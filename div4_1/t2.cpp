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
    int n;
    cin >> n;
    int w[n + 1][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // cin >> w[i][j];
            char a;
            cin >> a;
            w[i][j] = a - '0';
        }
    }
    int f = 0;
    int maxx = 0;
    int pos = 0;
    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = 0; j < n; j++){
            x += w[j][i];
        }
        w[n][i] = x;
        if(x > maxx){
            maxx = x;
            pos = i;
        }
        if(x != 0){
            f = i;
        }
    }
    for(int i = f; i < pos; i++){
        if(w[n][i] != w[n][pos - i + pos - i]){
            cout << "SQUARE" << ENDL;
            return;
        }
    }
    if(w[n][f] == w[n][pos]){
        cout << "SQUARE" << ENDL;
            return;
    }
    cout << "TRIANGLE" << ENDL;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}