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
    freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];

    sort(all(massive));

    int left = -1;
    int right = n;
    int target = 2500;
    for(auto it : massive) cout << it << " ";cout << ENDL;
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(target >= massive[mid]){
            left = mid;
        } else if(target < massive[mid]){
            right = mid;
        } 
    }
    cout << left << ENDL;
    
    


    endd
}