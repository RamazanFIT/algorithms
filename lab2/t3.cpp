#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        if((i + 1) % 2 != 0){
            cout << a << " ";
        }
    }
    cout << ENDL;


    endd
}