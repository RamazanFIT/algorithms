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

bool check(vector<pair<int, int> > & a, vector<pair<int, int> > & b, int k, int x){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if((a[i].first <= x) and (b[i].first <= x) and (a[i].second <= x) and (b[i].second <= x)) cnt++;
    }
    return (cnt >= k);
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int n, k;
    cin>>n>>k;
    vector<pair<int, int> > a(n);
    vector<pair<int, int> > b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    // cout << a[0].first << " " << a[0].second << ENDL;
    int left = 0;
    int right = INT_MAX;
    int ans = INT_MAX;
    while(right - left > 1){
        int mid = (right + left) / 2;
        // cout << mid << ENDL;
        if(check(a, b, k, mid)){
            // cout << mid << ENDL;
            right = mid;
            ans = min(mid, ans);
        } else{
            left = mid;
        }
    }
    cout << ans << ENDL;


    endd
}