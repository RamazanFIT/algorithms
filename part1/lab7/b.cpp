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
    vector<int> massive1(n);
    for(int i = 0; i < n; i++){
        cin >> massive1[i];
    }
    int m;
    cin >> m;
    vector<int> massive2(m);
    for(int i = 0; i < m; i++){
        cin >> massive2[i];
    }
    
    int index = 0;
    int index2 = 0;
    while(true){
        if(index >= n or index2 >= m){
            break;
        }

        if(massive1[index] > massive2[index2]){
            cout << massive2[index2] << " ";
            index2++;
        } else{
            cout << massive1[index] << " ";
            index++;
        }
       
    }
    for(int i = index; i < n; i++){
        cout << massive1[i] << " ";
    }
    for(int i = index2; i < m; i++){
        cout << massive2[i] << " ";
    }


    endd
}