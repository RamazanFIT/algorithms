#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


bool check(vector<int> & massive, int f, int x){
    int cnt = 0;
    for(int i = 0; i < massive.size(); i++){
        
        int sum = 0;
        while(sum < massive[i]){
            sum += x;
            cnt++;
        }
        if(cnt > f){
            return false;
        }

    }
    return cnt <= f;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    int f;
    cin>>f;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }

    int left = 0;
    int right = INT_MAX;
    int ans = INT_MAX;
    while(right - left > 1){
        int mid = (left + right) / 2;
        if(check(massive, f, mid)){
            right = mid;
            ans = min(ans, mid);
        } else{
            left = mid;
        }
    }
    cout << ans << ENDL;


    endd
}