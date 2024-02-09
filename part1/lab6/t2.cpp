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
        cin >> massive[i];
    }
    sort(all(massive));

    int minimum = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        int k = abs(massive[i] - massive[i + 1]);
        if(minimum > k){
            minimum = k;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(minimum == abs(massive[i] - massive[i + 1])){
            cout << massive[i] << " " << massive[i + 1] << " ";
        }
    }
    
    
    


    endd
}