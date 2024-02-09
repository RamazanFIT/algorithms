#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<vector<int> > memo(1005, vector<int>(1005, -1));


int count(vector<int> & a, vector<int> & b, int i, int j){
    if(i >= a.size() || j >= b.size()) return 0;
    if(memo[i][j] != -1){
        return max(memo[i][j], 0);
    } 
    if(a[i] == b[j]){
        
        memo[i][j] = max(1 + count(a, b, i + 1, j + 1), max(count(a, b, i + 1, j), count(a, b, i, j + 1)));
    } else{
        memo[i][j] = max(count(a, b, i + 1, j), count(a, b, i, j + 1));
    }
    return max(memo[i][j], 0);
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    set<int> set_;
    vector<int> massive;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
     
            set_.insert(a);
            massive.push_back(a);

    }
    vector<int> sorted;
    for(auto it : set_){
        sorted.push_back(it);
    }
    // for(auto i : sorted) cout << i << " ";cout << ENDL;
    // for(auto i : massive) cout << i << " ";cout << ENDL;
    
    cout << count(massive, sorted, 0, 0);
    
    


    endd
}