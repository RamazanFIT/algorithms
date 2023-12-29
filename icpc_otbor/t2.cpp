#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> ans;
    int k = n;
    vector<int> massive;
    while(k > 0){
        massive.push_back(k % 10);

        k /= 10;
    }

    for(int i = massive.size() - 1; i >= 0; i--){
        if(massive[i] != 0){
            int a = massive[i];
            int j = i;
            while(j > 0){
                a *= 10;
                j--;
            }
            ans.push_back(a);
        }
    }
    cout << ans.size() << ENDL;
    for(auto it : ans) cout << it << " ";
    cout << ENDL;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int n;
    cin>>n;
    while(n--) solve();
    


    endd
}