// 
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> massive(n + 1);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    int ans = (-1002) * 10;
    int tmp = (-1002) * 10;
    int flag = (massive[0] % 2ll);
    for(int i = 0; i < n; i++){
        // cout << flag << " " << massive[i] % 2 << ENDL;
        if(flag == int((massive[i] + 10000) % 2ll)){
            // cout << "ef";
            ans = max(ans, tmp);
            tmp = massive[i];
            ans = max(ans, tmp);
        } else{
            ans = max(ans, tmp);
            //  cout << tmp << " " << massive[i] << ENDL;
            tmp = max(tmp + massive[i], massive[i]);
            ans = max(ans, tmp);
           
            flag = ((massive[i] + 10000) % 2ll);
        }
        // cout << ans << ENDL;
    }
    ans = max(ans, tmp);
    cout << ans << ENDL;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve();
    
    


    endd
}