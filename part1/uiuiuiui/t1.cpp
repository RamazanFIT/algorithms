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
    vector<int> massive(n);
    repeat(n) cin >> massive[_];

    char a = 'a';
    int cnt = 0;
    // map<char, int> mapa;
    map<char, int> mapa2;
    vector<char> ans(n);
    repeat(n){
        if(massive[_] == 0){
            mapa2[a + cnt] = 0;
            ans[_] = a + cnt;
            cnt++;
        } else{
            for(auto it : mapa2){
                if(it.second + 1 == massive[_]){
                    ans[_] = it.first;
                    mapa2[it.first]++;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i];
    }
    cout << endl;
    // set<int> sett;
    // repeat(n){
    // }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;cin >> n;
    repeat(n) solve();

    endd
}