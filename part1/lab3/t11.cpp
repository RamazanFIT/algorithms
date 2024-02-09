#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

bool check(vector<int> & massive, int h, int x){
    int spend_time = 0;
    for(int i = 0; i < massive.size(); i++){
        if(massive[i] % x == 0){
            spend_time += massive[i] / x;
        } else{
            spend_time += massive[i] / x + 1;
        }
    }
    return spend_time <= h;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    int h;
    cin>>h;
    vector<int> massive(n);
    for(auto & it : massive) cin >> it;

    int left = 0;
    int right = INT_MAX;
    int ans = INT_MAX;
    while(right - left > 1){
        int mid = (right + left) / 2;

        if(check(massive, h, mid)){
            ans = min(ans, mid);
            right = mid;
        } else{
            left = mid;
        }
    }
    cout << ans << ENDL;
    


    endd
}