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

void add(int left, int right, int i, int v, int x, vector<int> & massive){
    if(right - left == 1){
        massive[x] = v;
    } else{
        int middle = (right + left) / 2;
        if(i >= left and i < middle){
            add(left, middle, i, v, x * 2, massive);
        } else{
            add(middle, right, i, v, x * 2 + 1, massive);
        }
        massive[x] = massive[x * 2] + massive[2 * x + 1];
    }
}

int sum(int left, int right, int lx, int rx, int x, vector<int> & massive){
    if(lx >= right or rx <= left){
        return 0;
    }

    if(left >= lx and right <= rx){
        return massive[x];
    }

    int middle = (left + right) / 2;

    int sum1 = sum(left, middle, lx, rx, x * 2, massive);
    int sum2 = sum(middle, right, lx, rx, x * 2 + 1, massive);
    return sum1 + sum2;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> massive(n * 10 + 3);

    while(k--){
        char Q;
        int l, r;
        cin >> Q >> l >> r;
        if(Q == 'A'){
            add(1, n * 2 + 3, l, r, 1, massive);
        } else{
            cout << sum(1, n * 2 + 3, l, r + 1, 1, massive) << ENDL;
        }
    }
    


    endd
}