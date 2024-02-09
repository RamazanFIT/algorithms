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

const int SIZE = 2e5;
vector<int> tree(4 * SIZE);


void create_tree(int left, int right, int x){
    if(right - left == 1){
        tree[x] = 1ll;
    } else{
        int middle = (right + left) / 2;
        create_tree(left, middle, x * 2);
        create_tree(middle, right, x * 2 + 1);
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }
}

int get(int left, int right, int x, int i){
   
    if(tree[x] == 0) return 0;
    if(right - left == 1){
        tree[x] = 0;
        return left;
    } else{
        int middle = (right + left) / 2;
        int to_return1 = 0;
        int to_return2 = 0;
        if((i < middle)){
            to_return1 = get(left, middle, 2 * x, i);
        } 
        if(to_return1 == 0) {
            to_return2 = get(middle, right, 2 * x + 1, i);
        }
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
      
        if(to_return1 != 0 and to_return2 != 0){
            return min(to_return1, to_return2);
        } else{
            return to_return1 + to_return2;
        }
    }
  
}

void update(int left, int right, int x, int i){
    if(right - left == 1){ 
        tree[x] = 1;
        return;
    } else{
        int middle = (right + left) / 2;
        if(i >= left and i < middle){
            update(left, middle, x * 2, i);
        } else{
            update(middle, right, 2 * x + 1, i);
        }
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
  
    }

}

signed main(){
    
    goodluck
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    create_tree(1, SIZE, 1);
    int q;
    cin >> q;

    while(q--){
        int a;
        cin >> a;
        if(a < 0){
            update(1, SIZE, 1, -a);
        } else{
            cout << get(1, SIZE, 1, a) << ENDL;
        }
    }
  

    endd
}