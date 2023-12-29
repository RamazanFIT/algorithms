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
    while(cin >> n){
        int k;
        cin >> k;
        vector<int> massive(k);
        for(int i = 0; i < k; i++){
            cin >> massive[i];
        }
        // for(int i = 0; i < k; i++){
        //     cout << massive[i] << " ";
        // } cout << ENDL;
     
        cout << "Sums of " << n << ":" << ENDL;
        bool flag = true;
        vector<string> ans;
        set<string> check;
        for(int i = 1; i <= k; i++){
            vector<bool> bolean(k, 0);
            for(int j = k - 1; j > k - 1 - i; j--){
                bolean[j] = 1;
            }
            do
            {
                int sum = 0;
                vector<int> tmp;
                for(int j = 0; j < k; j++){
                    if(bolean[j]){
                        // cout << massive[j] << " ";
                        sum += massive[j];
                        tmp.push_back(massive[j]);
                    }
                } 
                // for(int j = 0; j < i; j++){
                //     cout << tmp[j] << " " ;
                // } cout << ENDL;
                if(sum == n){
                    string s = "";
                    flag = false;
                    if(tmp.size() == 1){
                        // cout << tmp[0] << ENDL;
                        s += to_string(tmp[0]);
                        if(check.find(s) == check.end()){
                            // cout << s << ENDL;
                            ans.push_back(s);
                            check.insert(s);
                        }
                    } else{
                        sort(tmp.rbegin(), tmp.rend());
                        for(int j = 0; j < tmp.size() - 1; j++){
                            // cout << tmp[j] << "+";
                            s += to_string(tmp[j]) + "+";
                        }
                        // cout << tmp[tmp.size() - 1] << ENDL;
                        s += to_string(tmp[tmp.size() - 1]);
                        if(check.find(s) == check.end()){
                            // cout << s << ENDL;
                            ans.push_back(s);
                            check.insert(s);
                        }
                    }
                }
            } while (next_permutation(all(bolean)));
            
        }
        if(flag)
        cout << "NONE" << ENDL;
        else{
            sort(ans.rbegin(), ans.rend());
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << ENDL;
            }
        }
    }
    
    


    endd
}