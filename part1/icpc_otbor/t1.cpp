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
    string a, b;
    cin>>a>>b;
    
    for(int i = 0; i < a.size(); i++){
        if(!((a[i] == 'G' or a[i] == 'B') and (b[i] == 'G' or b[i] == 'B'))){
            if(a[i] != b[i]){
                cout << "NO" << ENDL;
                return;
            }
        }
    }

    cout << "YES" << ENDL;
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