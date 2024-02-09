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

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << n / 2 << ENDL;
        repeat(n / 2){
            cout << 2 << " ";
        }
    } else{
        cout << (n - 3) / 2 + 1 << ENDL;
        repeat((n - 3) / 2){
            cout << 2 << " ";
        }
        cout << 3;
    }
    


    endd
}