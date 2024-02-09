#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define mod 13
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int exponenta(int number, int power){
    if(power == 0){
        return 1ll;
    } else if(power == 1){
        return number % int(mod);
    }
    int x = exponenta(number, (power / 2) % int(mod)) % int(mod);
    if(power % 2 == 0) return (x * x) % int(mod);
    else return ((x * x) % int(mod) * (number % int(mod))) % int(mod);
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    // double a, b;
    // cin >> a >> b;
    // cout << int(ceil(a / b ))% int(mod) << ENDL;
    // cout << (int(a) * exponenta(b, mod - 2)) % int(mod);


    endd
}