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
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        massive[i] = i + 1;
    }
    vector<int> to_get(n);
    vector<int> tmp(n);

    for(int i = 0; i < n; i++){
        cin >> to_get[i];
        tmp[i] = to_get[i];
    }
    int cnt = 1;
    while(true){
        if(tmp == massive){
            cout << cnt << ENDL;
            return 0;
        } else{
            vector<int> tmp2(n);
            for(int i = 0; i < n; i++){
                tmp2[i] = to_get[tmp[i] - 1]; 
            }
            for(int i = 0; i < n; i++){
                tmp[i] = tmp2[i];
            }
        }
        cnt++;
    }


    endd
}