// Bismillah
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int n;
bool flag = false;

void rec(int x, set<int> check, int h){
    if(x == n and check.size() <= h){
        for(auto it : check){
            cout << it;
        }
        cout << endl;
        flag = true;
        return;
    }
    if(flag or (check.size() + 1) > h) return;
    for(int i = 1; i < 10; i++){
        if(check.find(i) == check.end()){
            check.insert(i);
            rec(x + i, check, h);
            check.erase(i);
        }
    }
}

void solve(){

    cin >> n;
    // if(n > 45){
    //     cout << -1 << ENDL;
    //     return;
    // }
    // for(int i = 0; i < 10; i++){
    //     if(flag) break;
    //     rec(0, set<int>(), i);
    // }
    // if(!flag)
    // cout << -1 << ENDL;

    // flag = false;

    vector<int> massive = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 189, 289, 389, 489, 589, 689, 789, 1789, 2789, 3789, 4789, 5789, 6789, 16789, 26789, 36789, 46789, 56789, 156789, 256789, 356789, 456789, 1456789, 2456789, 3456789, 13456789, 23456789, 123456789, -1, -1, -1, -1, -1};
    cout << massive[n - 1] << ENDL;
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t;cin>>t;repeat(t) solve();
    


    endd
}