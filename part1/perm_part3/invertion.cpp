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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    for(int i = n; i >= 1;i--){
        if(k <= (i - 1)){
            for(int j = 1; j < i - k; j++){
                cout << j << " ";
            }
            cout << i << " ";
            for(int j = i - k; j < i; j++){
                cout << j << " ";
            }
            return 0;
        } else{
            k -= (i - 1);
        }
        cout << i << " ";
    }
    


    endd
}