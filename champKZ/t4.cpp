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

int n, m;

using namespace std;

int get(int n){
    int res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    freopen("std.out", "w", stdout);

    int a, b;
    cin >> a >> b;
    // for(a = 0; a < 1000; a++){
    //     for(b = 0; b < 1000; b++){
            for(int i = 0; i < 1000; i++){
                if(get(i + a) == get(i + b)){
                    cout << i << ENDL;
                    // cout << a << " " << b << ENDL;
                    // break;
                }
            }
    //     }
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x, y;
            cin >> x >> y;
            while(true){
                int a;
                cin >> a;
                if(a == 0){
                    break;
                }
                
            }
        }
    }
    
    endd
}