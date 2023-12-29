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
    int w[n];
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    int x;
    cin >> x;
    sort(w, w + n);
    int left = -1;
    int right = n;
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(w[mid] > x){
            right = mid;
        } else if(w[mid] < x){
            left = mid;
        } else{
            cout << "Yes" << ENDL;
            return 0;
        }
    }
    cout << "No" << ENDL;
    
    


    endd
}