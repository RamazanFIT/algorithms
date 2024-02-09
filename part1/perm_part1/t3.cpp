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
    freopen("success.in", "r", stdin);
    freopen("success.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive1(n);
    vector<int> massive2(n);
    for(int i = 0; i < n; i++){
        cin >> massive1[i];
    }
    massive2 = massive1;
    next_permutation(all(massive1));
    if(massive1 != massive2){
        for(int i = 0; i < n; i++){
            cout << massive1[i] << " ";
        }
    } else{
        sort(all(massive1));
        for(int i = 0; i < n; i++){
            cout << massive1[i] << " ";
        }
    }


    endd
}