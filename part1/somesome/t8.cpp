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

    string n;
    cin >> n;
    if('9' - n[0] != 0){
        int i = 0;
        n[i] = char(min(n[i] - '0', '9' - n[i]) + '0');
    }
    for(int i = 1; i < n.size(); i++){
        n[i] = char(min(n[i] - '0', '9' - n[i]) + '0');
    }
    cout << n;
    


    endd
}