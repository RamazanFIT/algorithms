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

void solve(){
    int n;
    cin >> n;
    vector<int> massive(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> massive[i];
    }
    int x = 0;
    int y = 0;
    int ans = INT_MIN;
    int xx = INT_MIN;
    int yy = INT_MIN;
    for(int i = 1; i <= n; i+=2){
        x += max(massive[i], 0ll);
        xx = max(massive[i], xx);
    }
    for(int i = 2; i <= n; i+=2){
        y += max(massive[i], 0ll);
        yy = max(massive[i], yy);
    }

    // cout << xx << " " << yy << ENDL;
    if(xx < 0 and yy < 0){
        cout << max(xx, yy) << ENDL;
    } else{
        cout << max(x, y) << ENDL;
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std1.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    
    

    endd
}