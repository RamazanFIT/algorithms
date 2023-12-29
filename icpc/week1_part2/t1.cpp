#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    int power;
    int t;
    while(cin >> n >> power >> t){
        int ans = 1;
        n %= t;
        while(power > 0){
            if(power % 2 != 0){
                ans = (ans * n) % t;
                
            }
            n = (n * n) % t;
            power =  (power >> 1);
            ans = ans % t;
        }
        cout << (ans % t) % t << ENDL;
        
    }


    endd
}