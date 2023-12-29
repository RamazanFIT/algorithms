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
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        massive[i] = int(a);
    }
    
    char a;
    cin >> a;
    int target = int(a);
    // for(int i = 0; i < n; i++){
    //     cout << massive[i] << " ";
    // }
    // cout << endl;
    if(target + 1 >= massive[massive.size() - 1])
    cout << char(massive[0]);
    else
    cout << char(massive[upper_bound(all(massive), target + 1) - massive.begin()]);
    // cout << target;

    


    endd
}