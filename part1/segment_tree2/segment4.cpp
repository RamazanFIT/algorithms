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

const int SIZE = 4 * 1e5 + 1;

vector<int> massive(SIZE, INT_MIN);
vector<int> tree_max1(SIZE, INT_MIN);
vector<int> tree_max2(SIZE, INT_MIN);

void create_tree(int left, int right, int x){
    if(right - left == 1){
        tree_max1[x] = massive[left];
    } else{
        int middle = (right + left) / 2;
        create_tree(left, middle, 2 * x);
        create_tree(middle, right, 2 * x + 1);
        vector<int> tmp;
        tmp.push_back(tree_max1[x * 2]);
        tmp.push_back(tree_max2[x * 2]);
        tmp.push_back(tree_max1[x * 2 + 1]);
        tmp.push_back(tree_max2[x * 2 + 1]);
        sort(tmp.rbegin(), tmp.rend());
        tree_max1[x] = tmp[0];
        tree_max2[x] = tmp[1];
    }
}

pair<int, int> get_max(int left, int right, int lx, int rx, int x){
    if(lx >= right || rx <= left){
        return make_pair(INT_MIN, INT_MIN);
    }
    if(left >= lx and right <= rx){
        return make_pair(tree_max1[x], tree_max2[x]);
    }
    int middle = ( left + right ) / 2;

    pair<int, int> p1 = get_max(left, middle, lx, rx, x * 2);
    pair<int, int> p2 = get_max(middle, right, lx, rx, x * 2 + 1);

    vector<int> tmp;
    tmp.push_back(p1.first);
    tmp.push_back(p1.second);
    tmp.push_back(p2.first);
    tmp.push_back(p2.second);
    sort(tmp.rbegin(), tmp.rend());
    return make_pair(tmp[0], tmp[1]);
}

void update(int left, int right, int x, int i, int value){
    if(right - left == 1){
        tree_max1[x] = value;
        return;
    }
    int middle = ( right + left ) / 2;
    if(i >= left and i < middle){
        update(left, middle, 2 * x, i, value);
    } else{
        update(middle, right, 2 * x + 1, i, value);
    }
    vector<int> tmp;
    tmp.push_back(tree_max1[x * 2]);
    tmp.push_back(tree_max2[x * 2]);
    tmp.push_back(tree_max1[x * 2 + 1]);
    tmp.push_back(tree_max2[x * 2 + 1]);
    sort(tmp.rbegin(), tmp.rend());
    tree_max1[x] = tmp[0];
    tree_max2[x] = tmp[1];
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> massive[i];
    }
    create_tree(1, n + 1, 1);
    int q;
    cin >> q;
    while(q--){
        char a;
        cin >> a;                                              
        int l, r;
        cin >> l >> r;
        if(a == 'Q'){
            pair<int, int> tmp = get_max(1, n + 1, l, r + 1, 1);
            cout << tmp.first + tmp.second << ENDL;
        } else{
            update(1, n + 1, 1, l, r);
        }
    }
    
    

    endd
}