#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

vector<vector<int> > ans;

void rec(int n, vector<int> path){
    if(n == 0){
        // sort(path.rbegin(), path.rend());
        ans.push_back(path);
        
        return;
    } else{
        for(int i = 1; i <= n; i++){
            if(path.size() != 0 and path[path.size() -1] >= i){
            path.push_back(i);
            rec(n - i, path);
            path.pop_back();}
            else if(path.size() == 0){

            path.push_back(i);
            rec(n - i, path);
            path.pop_back();
            }
        }
    }
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    rec(n, vector<int>());
    // sort(all(ans));
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        } cout << ENDL;
    }

    


    endd
}