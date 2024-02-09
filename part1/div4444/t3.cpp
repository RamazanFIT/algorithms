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
using ll = long long;
using namespace std;

set<int> preCalc;


bool check(int f){
    return int(sqrt(f)) * int(sqrt(f)) == f;
}
void solve(){
    int n;cin>>n;

    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    if(check(sum)){
        cout << "YES" << ENDL;
    } else{
        cout << "NO" << ENDL;
    }

}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    // for(int i = 0; i < 1e6; i++){
    //     preCalc.insert(i * i);
    // }
    int t;cin>>t;
    repeat(t) solve();
    


    endd
}