#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define mod 1e9 + 7
#define int ll
#define ull unsigned long long 
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;


int multiply(int a, int b){
    if(b == 0) return 0ll;
    if(b == 1){
        return a % int(mod);
    }
    int ans = 0;
    ans = ((multiply(a, (b / 2)  % int(mod) ) % int(mod)) * 2) % int(mod);
    return (ans  % int(mod) + a * (b % 2)) % int(mod);
}

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

    
    int n, m;
    cin >> n >> m;
    n--;
    // /////////////(n + m) ! / (n !) * (m !);
    if(n > m){
        int ans = 1;
        for(long long i = n + m; i > n; i--){
            ans %= int(mod);
            ans = (multiply(i, ans)) % int(mod);
        }
        int mm = 1;
        for(long long i = m; i >= 1; i--){
            ans %= int(mod);
            mm = (multiply(i, mm)) % int(mod);
        }
        cout << (((ans % int(mod)) * (exponenta(mm, int(mod) - 2) % int(mod))) % int(mod)) % int(mod) << ENDL;
    } else{
        int ans = 1;
        for(long long i = n + m; i > m; i--){
            ans %= int(mod);
            ans = (multiply(i, ans)) % int(mod);
        }
        int mm = 1;
        for(long long i = n; i >= 1; i--){
            ans %= int(mod);
            mm = (multiply(i, mm)) % int(mod);
        }
        cout << (((ans % int(mod)) * (exponenta(mm, int(mod) - 2) % int(mod))) % int(mod)) % int(mod) << ENDL;
    }
    // cout << multiply(5, 7);


    endd
}