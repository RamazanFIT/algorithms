#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define int ll
#define repeat(x) for(int mmmmm = 0; mmmmm < x; mmmmm++)
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
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
    // freopen("std.out", "w", stdout);

    
    int n;
    cin >> n;
    repeat(n){
        int a, b;
        cin >> a >> b;
        if((get(a) % 9) != (get(b) % 9)){
            cout << "NO" << ENDL;
        } else{
            int x = get(a);
            int y = get(b);
            cout << "YES" << " " << (y - x) * 9 << ENDL;
        }
    }


    endd
}