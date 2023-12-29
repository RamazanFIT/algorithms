#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int long long
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool check(vector<int> & massive, int x, int k){
    for(int i = 0; i < massive.size(); i++){
        if(k > massive[i]){
            x-=(k - massive[i]);
        }
    }
    return x >= 0;
}


void solve(){
    int n;
    cin>>n;
    int x;
    cin>>x;

    vector<int> massive(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> massive[i];
      
    }
    int left = 1;
    int right = INT_MAX;
    int ans = 1;
    while(right - left > 1){
        int mid = (left + right) / 2;
        if(check(massive, x, mid)){
            ans = max(ans, mid);
            left = mid;
        } else right = mid;
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