#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
// 1 - (

// 0 - )
bool check(vector<bool> v){
    if(v.size() == 1 or v.size() == 0){
        return 0;
    }
    stack<bool> st;
    st.push(v[0]);
    for(int i = 1; i < v.size(); i++){
        if(!st.empty() and st.top() == 1 and v[i] == 0){
            if(!st.empty())
            st.pop();
        } else{
            st.push(v[i]);
        }
    }
    return st.empty();
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    n *= 2;

    vector<bool> bolean(n);
    int c = int(n - 1 - int(n / 2));
    for(int i = n - 1; i > c; i--){
        bolean[i] = true;
    }
    vector<vector<bool> > ans;
    do
    {
        if(check(bolean)){
            ans.push_back(bolean);
        }
    } while (next_permutation(all(bolean)));
    
    sort(all(ans));
    for(int i = ans.size() - 1; i >= 0; i--){
        for(int j = 0; j < ans[i].size(); j++){
            if(ans[i][j] == 1){
                cout << '(';
            } else{
                cout << ")";
            }
        }
        cout << ENDL;
    }
    
    


    endd
}