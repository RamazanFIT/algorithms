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
    cin >> n;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        if(a == 'A') cnt1++;
        else cnt2++;
    }
    if(cnt1 > cnt2){
        cout << "A" << ENDL;

    } else if(cnt2 > cnt1){
        cout << "B" << ENDL;
    } else{
        cout << "?" << ENDL;
    }
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