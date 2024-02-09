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
    vector<int> a(n);
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++) cin>>b[i];
    
    int index1 = 0, index2 = n - 1;
    while(a[index1] == b[index1]){
        if(index1 >= n) break;
        index1++;
    }
    while(a[index2] == b[index2]){
        if(index2 < 0) break;
        index2--;
    }

    sort(a.begin() + index1, a.begin() + index2 + 1);
    if(a == b){
        cout << "YES" << ENDL;
    } else cout << "NO" << ENDL;
    

    endd
}