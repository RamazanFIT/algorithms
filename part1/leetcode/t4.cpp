#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int n;
bool flag = true;
vector<int> massive;
void rec(int money, int sum, int i, vector<int> path){
    
    if(money == sum){
        cout << path.size() << ENDL;
        for(auto it : path){
            cout << it << " ";
        }
        flag = false;
        return;
    } else{
        // 1
        if(i >= n) return;
        rec(money, sum, i + 1, path);
        // 2
        path.push_back(massive[i]);
        rec(money, sum + massive[i], i + 1, path);
        // 3
        path.push_back(massive[i]);
        rec(money, sum + 2 * massive[i], i + 1, path);
    }

}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    int money;
    cin>>money>>n;
    
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        massive.push_back(a);
    }
    vector<int> path;
    rec(money, 0, 0, path);
    if(flag)
    cout << -1 << ENDL;
    


    endd
}