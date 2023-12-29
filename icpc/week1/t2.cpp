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
    cin >> n;
    int power;
    cin >> power;
    int cnt = 1;
    int k = n;
    if(power == 0){
        cout << 1 << ENDL;
        return 0;
    }
    while(cnt < power and k * k <= n){
        k = k * k;
        cnt*=2;
    }
    for(int i = cnt; i < power; i++) k *= n;

    cout << k << ENDL;





    


    endd
}