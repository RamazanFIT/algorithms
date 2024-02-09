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

bool check(vector<int> & massive, int k,  int x){
    int cnt = 1;
    int last = massive[0];

    for(int i = 1; i < massive.size(); i++){
        if(massive[i] - last >= x){
            cnt++;
            last = massive[i];
        }
    }
    return cnt >= k;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];

    int left = -1;
    int right = INT_MAX  ;
    int ans = 0;
    while(right - left > 1){
        int mid = (right + left) / 2;

        if(check(massive, k, mid)){
            left = mid;
            ans = mid;
        } else{
            right = mid;
        }
    }
    cout << ans << ENDL;
    
    endd
}