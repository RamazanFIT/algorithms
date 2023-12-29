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
    vector<int> w1(n);
    vector<int> w2(n);
    for(int i = 0; i < n; i++) cin >> w1[i];
    for(int i = 0; i < n; i++) cin >> w2[i];

    int l = 0;
    int r = 0;
    int minimum = 0;
    int maximum = 0;
    while(true){
        if(l >= n){
            break;
        }
        if(w1[l] > w2[r]){
            l++;
            r++;
            maximum++;
        } else{
            l++;
        }
    }
    l = n - 1;
    r = n - 1;
    while(true){
        if(l < 0) break;
        if(w1[l] < w2[r]){
            l--;
            r--;
            minimum++;
        } else{
            l--;
        }
    }
    minimum = n - minimum;
    cout << maximum - minimum + 1 << ENDL;
    for(int i = minimum; i <= maximum; i++){
        cout << i << " ";
    }
    // cout << minimum << " " << maximum << ENDL;


    endd
}