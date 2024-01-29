#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> massive(n), a(n + 1), b(n + 1);
    repeat(n){
        cin >> massive[_];
    }
    repeat(n){
        a[_ + 1] = a[_] + massive[_];
        b[_ + 1] = b[_] + massive[n - 1 - _];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int target = a[i];
        int left = 0;
        int right = (n - i + 1);
        int k = -1;
        while(right - left > 1){
            int mid = (right + left) / 2;
            if(target > b[mid]){
                left = mid;
            } else if(target < b[mid]){
                right = mid;
            } else{
                k = mid;
                break;
            }
        }
        if(k != -1){
            ans = max(ans, k + i);
        }
    }
    cout << ans << ENDL;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    repeat(n) solve();
    


    endd
}