#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    repeat(n) cin >> a[_];
    repeat(m) cin >> b[_];
    
    sort(all(a));
    sort(all(b));
    // print(a);
    // cout << ENDL;
    // print(b);
    // cout << ENDL;

    int ans = 0;
    int l1 = 0, l2 = 0, r1 = n - 1, r2 = m - 1;
    repeat(n){
        if(abs(a[l1] - b[r2]) > abs(b[l2] - a[r1])){
            // cout << a[l1] << " - " << b[r2] << ENDL;
            ans += abs(a[l1] - b[r2]);
            l1++;
            r2--;
        } else{
            // cout << a[l2] << " - " << b[r1] << ENDL;

            ans += abs(b[l2] - a[r1]);
            l2++;
            r1--;
        }
    }    
    cout << ans << ENDL;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int x;
    cin >> x;
    repeat(x) solve();
    


    endd
}