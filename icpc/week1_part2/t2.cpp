#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define ull unsigned long long
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

ull n;
ull power;
ull t;
ull c;



ull multiply(ull a, ull b){

    if(b == 1){
        return a % t;
 
    } else if(b == 0) return 0ll;
    ull full = ((multiply(a, b / 2) % t) * ll(2)) % t;
    return (full + (b % 2) * a )% t;



}

ull rec(ull x, ull y){
    if(y == 0) return 1ll % t;
    if(y == 1) return x % t;
    
    ull tmp = rec(x % t, y / 2);
    if(y & ll(1)){
        return multiply((tmp % t), multiply((tmp % t), (x % t)) % t) % t;
    } else{
        return multiply((tmp % t), (tmp % t)) % t;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);


    while(cin >> n >> power >> t){
        cout << rec(n % t, power) % t << ENDL;
        
    }


    endd
}