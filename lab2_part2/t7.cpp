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
    int n, m;
    cin >> n >> m;
    cout << min(n + 1, m);
    // if(n > m){
        // cout << m << ENDL;
            for(int i = 0; i < m - 1; i++){
            for(int j = n - i; j < m; j++){
                cout << j << " ";
            }
            for(int j = 0; j < m - i; j++){
                cout << j << " ";
            }
            
        }
        for(int i = 0; i < m; i++){
                cout << i << " ";
        }
        for(int i = 0; i < m; i++){
            
        }
    // } 
    // for(int i = 0; i < m; i++){
    //     for(int j = n - i; j < n; j++){
    //         cout << j  << " ";
    //     }
    //     for(int j = 0; j < n - i; j++){
    //         cout << j << " ";
    //     }
    // }


}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;
    cin>>n;
    while(n--) solve();
    
    


    endd
}