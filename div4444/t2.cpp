#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n = 3;
    int sum = 'A' + 'B' + 'C';
    char w[n][n];
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
            if(w[i][j]=='?'){
                x = i;
                y = j;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
            if(w[x][i]!='?')
                cnt += w[x][i];
    }
    cout << char(sum - cnt) << ENDL;
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;
    repeat(t) solve();
    


    endd
}