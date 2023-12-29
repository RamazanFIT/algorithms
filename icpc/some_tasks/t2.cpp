#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void solve(){

    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    int max1 = 0;
    int max2 = 0;
    int min1 = 1e10;
    int min2 = 1e10;
    unsigned long long sum1 = 0;
    unsigned long long sum2 = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        max1 = max(max1, a);
        min1 = min(min1, a);
        sum1 += a; 
    }
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        max2 = max(max2, a);
        min2 = min(min2, a);
        sum2 += a;
    }

    if(k % 2 == 0){
        if(min1 >= max2){
            int tmp = sum1 - max1 + min2;
            if(max1 < max2){
                swap(max1, max2);
            }
            cout << tmp << ENDL;

        } else{
            int tmp = sum1 - min1 + max2;
            if(max1 < max2){
                swap(max1, max2);
            }
            cout << tmp - max1 + min(min1, min2) << ENDL;
        }
    } else{
        if(min1 >= max2){
            int tmp = sum1 - max1 + min2;
            if(max1 < max2){
                swap(max1, max2);
            }
            cout << tmp + max1 - min(min2, min1) << ENDL;
        } else{
            int tmp = sum1 - min1 + max2;
            if(max1 < max2){
                swap(max1, max2);
            }
            cout << tmp << ENDL;

        }
    }

    
    
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int n;
    cin >> n;
    while(n--) solve();
    


    endd
}