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


void add(int left, int right, int lx, int rx, int value, int x, vector<int> & ta){
    if(lx >= right or rx <= left){
        return;
    }
    if(left >= lx and right <= rx){
        ta[x] += value;
        return;
    }
    int middle = (left + right) / 2;
    add(left, middle, lx, rx, value, x * 2, ta);
    add(middle, right, lx, rx, value, x * 2 + 1, ta);
}   

int get(int left, int right, int x, int i, vector<int> & ta){
    // int ans = 0;
    if(right - left == 1){
        if(i == left)
        return ta[x];
    }
    int middle = (left + right) / 2;
    if(i >= left and i < middle){
        return ta[x] + get(left, middle, x * 2, i, ta);
    } else{
        return ta[x] + get(middle, right, x * 2 + 1, i, ta);
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    // vector<int> massive(n * 5 + 2);
    vector<int> ta(n * 5 + 2);
    
    while(k--){
        char a;
        cin >> a;
        if(a == 'A'){
            int l, r, d;
            cin >> l >> r >> d;
            l++;
            r++;
            add(1, n + 1, l, r + 1, d, 1, ta);
        } else{
            int i;
            cin >> i;
            cout << get(1, n + 1, 1, i + 1, ta) << ENDL;
        }
    }

    endd
}