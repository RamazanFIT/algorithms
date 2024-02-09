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
    int n = 1000;
    vector<int> massive(n, 0);
    for(int i = 0; i < n; i++){
        massive[i] = 100 + i;
    }

    int left = -1;
    int right = n;
    int target = 500;
    while(right - left > 1){
        int mid = (left + right) / 2;
        if(massive[mid] <= target){
            left = mid;
        } else{
            right = mid;
        }
    }
    cout << left << ENDL;
    cout << massive[left] << ENDL;


    endd
}