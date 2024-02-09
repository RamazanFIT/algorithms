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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int x;
    cin >> x;
    x--;
    vector<int> massive(n);
    int ans = 0;
    repeat(n) cin >> massive[_];
    if(massive[x]){
        ans++;
    }
    for(int i = 1; i <= n; i++){
        int l = x - i;
        int r = x + i;
        int cnt = 0;
        int d = 0;
        bool flag = false;
        if(l >= 0 and l < n){
            if(massive[l]) cnt++;
        } else{
            cnt++;
            d++;
            flag = true;
        }
        if(r >= 0 and r < n){
            if(massive[r]) cnt++;
        } else{
            cnt++;
            d++;
            flag = true;
        }
        if(d == 2) break;
        if(cnt == 2){
            ans++;
            ans++;
            if(flag) ans--;
        }
    }
    cout << ans << ENDL;
    
    


    endd
}