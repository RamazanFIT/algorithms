#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a += '1';
    b += '1';
    int ans = 0;
    bool flag = false;
    for(int i = 0; i <= n; i++){
        if(a[i] != b[i]){
            flag = true;
        }
        if(a[i] == b[i] and flag){
            ans++;
            flag = false;
        }
    }
    cout << ans << ENDL;
    


    endd
}