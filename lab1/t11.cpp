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
    // freopen("sdt.out", "w", stdout);
    int n;
    cin >> n;
    vector<char> k(n);
    for(int i = 0;i<n;i++){
        cin >> k[i];
    }
    deque<int> ses, kes;
    for(int i = 0;i<n;i++){
        if(k[i]=='K'){
            kes.push_back(i);
        }else{
            ses.push_back(i);
        }
    }


    endd
}