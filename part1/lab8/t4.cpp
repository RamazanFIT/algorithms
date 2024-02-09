#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll =  long long;
using namespace std;

signed main(){
    
    goodluck
    freopen("final.in", "r", stdin);
    freopen("final.out", "w", stdout);

    
    int n, p, k, d;
    cin >> n >> p >> k >> d;
    int ddd = d;
    int ppp = p;
    if(k > n or d > k){
        cout << "Wrong information";
        return 0;
    }
    vector<int> ans;
    if(d == 1){
    
        int jojo = p / k;
        int ost = p % k;
        // if(jojo == 0){
        //     cout << "Wrong information";
        //     return 0;
        // }
        for(int i = 0; i < k; i++){
             
                ans.push_back(jojo);
        }
        if(ost != 0)
        ans.push_back(ost);
        int tmp = ans.size();
        for(int i = 0; i < n - tmp; i++){
                
                ans.push_back(0);
        }
        // cout << ans.size() << " " << n <<ENDL;
        if(ans.size() != n){
            cout << "Wrong information";
            return 0;
        }
        sort(ans.rbegin(), ans.rend());
        for(int i = 0; i < n; i++){
            cout << ans[i] << ENDL;
        }
        return 0;
        
    }
    int cnt = 0;
    for(int i = 0; i <= n; i++){
        if((p - i >= 0) and (d > 0)){
            ans.push_back(i);
            p -= i;
            d--;
        } else{
            break;
        }
    }
    sort(ans.rbegin(), ans.rend());
  
    ans[0] += p;
    




    int z = ans.size();
    for(int i = 0; i < n - z; i++){
        // cout << 0 << endl;
        ans.push_back(0);

    }

    
    set<int> set_;
    for(int i = 0; i < k; i++){
        set_.insert(ans[i]);
    }

    if(set_.size() != ddd){
        cout << "Wrong information";
        return 0;
    }
 
    if(ans.size() != n){
        cout << "Wrong information";
        return 0;
    }
    
    int sum = 0;
    for(auto it : ans){
       
        sum += it;
    }
    if(sum != ppp){
        cout << "Wrong information";
        return 0;
    }

   
    for(int i = 0; i < n; i++){
        cout << ans[i] << ENDL;
    }

    endd
}