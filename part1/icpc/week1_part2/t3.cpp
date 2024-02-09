#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define ull ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

int n;
int power;
int t;
int c;

ull rec2(ull a, ull b){

    if(b == 1){
        return a % t;
 
    } else if(b == 0) return 0ll;
    ull full = ((rec2(a, b / 2) % t) * ll(2)) % t;
    return (full + (b % 2) * a )% t;

}

signed main(){
    
    goodluck

    while(cin >> n >> power >> t){
        int ans = 1;
        while(power > 0){
            if(power % 2 != 0){
                ans = rec2(ans, n);
               
            }
            c = n;
            n = rec2(n, n);
            power =  (power >> 1);
            ans = ans % t;
        }
        cout << (ans % t) % t << ENDL;
        
    }


    endd
}