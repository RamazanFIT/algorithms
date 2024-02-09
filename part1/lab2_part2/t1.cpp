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
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> massive(n, INT_MIN);
    int k = n;
    for(int i = x - 1; i < n; i+=x){
        
        if((i + 1) % y != 0){
            massive[i] = k;
            k--;
        }
    }
    int c = 1;
    for(int i = y - 1; i < n; i+=y){
    //     if(massive[i] == INT_MIN)
    //    { y = c;
    //     c++;
    //     }
        if((i + 1) % x != 0){
            massive[i] = c;
            c++;
        }
    }
    // for(int i = 0; i < n; i++){
    //     if(massive[i] == INT_MIN){
    //         massive[i] = c;
    //         c++;
    //     }
    // }
    int sum1 = 0;
    int sum2 = 0;
    // for(int i = 0; i < n; i++){
    //     if((i + 1) % x == 0){
    //         sum1+=massive[i];
    //     }
    //     if((i + 1) % y == 0){
    //         sum2 += massive[i];
    //     }
    // }
    for(int i = x - 1; i < n; i+=x){
        sum1 += massive[i];
    }
    for(int i = y - 1; i < n; i+=y){
        sum2 += massive[i];
    }
    cout << sum1 - sum2;
    cout << ENDL;


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