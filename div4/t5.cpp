#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> massive(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> massive[i];
        sum += massive[i];
    }
    int ans = (x + sum) / n;
    cout << ans << ENDL;
    sort(massive.rbegin(), massive.rend());
    for(int i = 0; i < n - 1; i++){
        if(ans - massive[i] >= 0){
            sum += massive[i];
        } else{
            sum -= massive[i];
        }
        
        int h = (x + sum) / (n - 1 - i);
        ans = max(h, ans);
    }
    cout << ans << ENDL;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    while(n--){
        solve();
    }
    


    endd
}