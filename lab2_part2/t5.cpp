#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int> massive(n);
    int k = 0;
    int sum = 0;
    for(auto it : massive){
        cin >> it;
        k ^= it;
        sum += it;
    }
    if(sum == 0){
        cout << 0 << ENDL;
        return;
    }
    if(k == 0){
        cout << 1 << ENDL;
        cout << 1 << " " << n << ENDL;
    }
    else{
        if(n % 2 == 0){
            cout << 2 << ENDL;
            cout << 1 << " " << n << ENDL;
            cout << 1 << " " << n << ENDL;
        }
        else{
            cout << 4 << ENDL;
            cout << 1 << " " << n << ENDL;
            cout << 1 << " " << 2 << ENDL;
            cout << 2 << " " << n << ENDL;
            cout << 2 << " " << n << ENDL;
        }
    }

}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}