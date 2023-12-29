#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];
    int x;
    cin>>x;

    int abstr = abs(massive[0] - x);
    int index = 0;
    for(int i = 0 ; i < n; i++){
        if(abs(massive[i] - x) < abstr){
            index = i;
            abstr = abs(massive[i] - x);
        }
    }
    cout << index << ENDL;
    
    


    endd
}