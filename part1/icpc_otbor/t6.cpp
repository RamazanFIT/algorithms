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
    int n, k;
    cin>>n>>k;
    
    int left = 0;
    int right = INT32_MAX;
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(mid % n != 0 and mid - mid / n == k){
            cout << mid << ENDL;
            return;
        } else if(mid - mid / n >= k){
            right = mid;
        } else{
            left = mid;
        }
    } 
    cout << left << ENDL;
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}