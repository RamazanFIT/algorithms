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
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, m, one, paypal;
    cin >> n >> m >> one >> paypal;
    // cout << (n / m) * paypal + one * (n - (n / m) * m);
    
    if(double(paypal) / m > one){
        cout << n * one;
    } else{
        int money = (n / m) * paypal;
        money += min(one * (n - (n / m) * m), paypal);
        cout << money;
    }

    endd
}