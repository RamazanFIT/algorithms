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
        cin >> massive[i];
    }

    vector<int> p(n);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }

    for(int k = n - 1; k >= 0; k--){
        int index = k - 1;
        while(true){
            int cnt = 0;
            for(int i = k - 1; i >= 0; i--){
                if(p[k] < p[i]){
                    cnt++;
                }
            }
            if(cnt == massive[k]){
                break;
            } else{
                swap(p[k], p[index]);
                index--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
    

    endd
}