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

int gcd_by_x_y(int a, int b, int & x, int & y){
    if(b == 0){
        x = 1; // тк прим a * x + b * y  = gcd(a, b) там при подстановке gcd(a, 0) = a = a * x + b * y = a * 1 + 0 * y = a * 1 + 0 = a; то есть gcd у 12 и 0 равен 12
        y = 0;
        return a;
    }
    int gcd = gcd_by_x_y(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return gcd;
}



void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, z, d;
    int f = gcd_by_x_y(a, b, x, y);
    int ans = gcd_by_x_y(f, c, d, z);
    // cout << ans << ENDL;
    // cout << x << " " << y << " " << z << ENDL;
    // cout << (ans == x * a + b * y + z * c) << ENDL;
    int cnt = 0;
    while(cnt < 10){
        cout << (ans == x * a + b * y + z * c) << ENDL;
        cout << x << " " << y << " " << z << ENDL;
        x += b;
        y -= a;
        cnt++;
    }
    // // if(x < 0){
    //     while(x  < 100000){
    //         cout << x << " " << y << ENDL;
    //         x += b;
    //         y -= a;
            
    //     }
    // // }
    // cout << x << " " << y << ENDL;

}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}