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
    
    vector<int> a(4), b(4);

    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> b[i];
    }
    sort(all(b));
    sort(all(a));
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i < 4; i++){
        sum1 += a[i];
    }
    for(int i = 1; i < 4; i++){
        sum2 += b[i];
    }

    if(sum1 > sum2){
        cout <<"aibark";
    } else if(sum1 < sum2){
        cout << "Na2a";
    } else{
        cout <<"Tekor";
    }
    endd
}