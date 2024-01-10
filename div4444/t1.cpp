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
    int w[3];
    for(int i = 0; i < 3; i++){
        cin >> w[i];
    }
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            if(w[i] == w[j]){
                // cout << w[i] << " " << w[j] << ENDL;
                cout << w[(3 - (i + j))] << ENDL;
                return;
            }
        }
    }

}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;
    cin >> t;
    repeat(t){
        solve();
    }
    
    


    endd
}