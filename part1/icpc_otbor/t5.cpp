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

void solve(){
    int n;
    cin>>n;
    vector<int> left;
    vector<int> right;
    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        char a;
        cin>>a;
        if(a == 'L'){
            left.push_back(n - 1 - i);
            ans += i;
        } else{
            ans += (n - 1 - i);
        }
        
    }
   
    int start = n / 2;
    if(n % 2 != 0){
        char a;
        cin>>a;
        ans += n / 2;
        start++;
    }
    for(int i = start; i < n; i++){
        char a;
        cin>>a;
        if(a =='R'){
            right.push_back(i);
            ans += (n - 1 - i);
        } else{
            ans += i;
        }
    }
    int index_left = 0;
    int index_right = right.size() - 1;
    for(int i = 0; i < n; i++){
        if(right.size() == 0){
            if(index_left < left.size()){
                // ans += left[index_left];
                // ans -= (n - 1 - left[index_left]);
                ans = max(ans, ans + 2*left[index_left] - n + 1);
                index_left++;
            }
        } else if(left.size() == 0){
            if(index_right >= 0){
                // ans += right[index_right];
                // ans -= (n - 1 - right[index_right]);
                ans = max(ans, ans + 2*right[index_right] - n + 1);
                index_right--;
            }
        } else
        if((index_left < left.size()) and (index_right >= 0) and (left[index_left] > right[index_right])){
            if(index_left < left.size()){
                // ans += left[index_left];
                // ans -= (n - 1 - left[index_left]);
                ans = max(ans, ans + 2*left[index_left] - n + 1);
                index_left++;
            }
            // cout << ans << " ";
        } else if(index_right >=0){
            if(index_right >= 0){
                // ans += right[index_right];
                // ans -= (n - 1 - right[index_right]);
                ans = max(ans, ans + 2*right[index_right] - n + 1);
                index_right--;
            }
            // cout << ans << " ";
        } else if(index_left < left.size()){
                // ans += left[index_left];
                // ans -= (n - 1 - left[index_left]);
                ans = max(ans, ans + 2*left[index_left] - n + 1);
                index_left++;
        }
            cout << ans << " ";
        
    }

    cout << ENDL;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--)solve();
    


    endd
}