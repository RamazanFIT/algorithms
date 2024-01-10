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

int get_size(int n){
    int cnt = 0;
    while(n > 0) n /= 10, cnt++;
    return cnt;
}

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << ENDL;
    } else if(n == 3){
        cout << "169\n196\n961" << ENDL;
    } else{
        cout << "16384\n31684\n36481\n38416\n43681" << ENDL;
    }
}с
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    repeat(n) solve();
    


    endd
}