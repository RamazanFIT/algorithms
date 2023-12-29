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

int w[2 * 100000 + 1];
vector<int> massive(2 * 100000 + 1);

int insert(int v, int left, int right){
    if(left == right){
        w[v] = massive[left - 1];
    } else{
        int middle = (left + right) / 2;
        insert(2 * v, left, middle);
        insert(2 * v + 1, middle + 1, right);
        // w[v] = min(w[2 * v], w[2 * v + 1]);
        w[v] = w[2 * v] + w[2 * v + 1];
    }
}

int give_ans(int v, int left, int right, int L, int R){
    if(L <= left and right <= R){
        return w[v];
    }
    if(R < left or L > right){
        return 0ll;
    }
    int middle = (right + left) / 2;
    return (give_ans(2 * v, left, middle, L, R) + give_ans(2 * v + 1, middle + 1, right, L, R));
}

signed main(){
    
    goodluck
    // freopen("stupid_rmq.in", "r", stdin);
    // freopen("stupid_rmq.out", "w", stdout);

    int n;
    cin >> n;
    int q;
    cin >> q;
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    insert(1, 1, n);
    
    
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << give_ans(1, 1, n, l, r) << ENDL;
    }

    


    endd
}