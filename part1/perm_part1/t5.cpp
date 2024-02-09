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
    // freopen("comb.in", "r", stdin);
    // freopen("comb.out", "w", stdout);

    int n, k, c;
    cin >> n >> k >> c;
    vector<bool> bolean(n);
    for(int i = n - 1; i > n - 1 - k; i--){
        bolean[i] = 1;
    }
    vector<vector<int> > ans;
    do
    {
        for(int i = 0; i < n; i++){
            cout << bolean[i] << " ";
        } cout << endl;
        // vector<int> tmp;
        // for(int i = n - 1; i >= 0; i--){
        //     if(bolean[i]){
        //         tmp.push_back(i + 1);
        //     }
        // }
        // ans.push_back(tmp);
    } while (next_permutation(all(bolean)));
    
    // sort(ans.begin(), ans.end());
    // for(int i = 0; i < k; i++){
    //     cout << ans[c][i] << " ";
    // }


    endd
}