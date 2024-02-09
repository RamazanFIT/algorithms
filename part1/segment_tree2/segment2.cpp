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

vector<int> massive(600004);
vector<int> massive_min(600004);
vector<int> massive_max(600004);

void create_min(int left, int right, int x){
    if(right - left == 1){
        massive_min[x] = massive[left];
    } else{
        int middle = (left + right) / 2;
        create_min(left, middle, x * 2);
        create_min(middle, right, x * 2 + 1);
        massive_min[x] = min(massive_min[x * 2], massive_min[x * 2 + 1]);
    }
}
void create_max(int left, int right, int x){
    if(right - left == 1){
        massive_max[x] = massive[left];
    } else{
        int middle = (left + right) / 2;
        create_max(left, middle, x * 2);
        create_max(middle, right, x * 2 + 1);
        massive_max[x] = max(massive_max[x * 2], massive_max[x * 2 + 1]);
    }
}

void set_min(int left, int right, int x, int pos, int value){
    if(right - left == 1){
        massive_min[x] = value;
    } else{
        int middle = (left + right) / 2;
        if(pos >= left and pos < middle){
            set_min(left, middle, 2 * x, pos, value);
        } else{
            set_min(middle, right, 2 * x + 1, pos, value);
        }
        massive_min[x] = min(massive_min[x * 2], massive_min[x * 2 + 1]);
    }
}

void set_max(int left, int right, int x, int pos, int value){
    if(right - left == 1){
        massive_max[x] = value;
    } else{
        int middle = (left + right) / 2;
        if(pos >= left and pos < middle){
            set_max(left, middle, 2 * x, pos, value);
        } else{
            set_max(middle, right, 2 * x + 1, pos, value);
        }
        massive_max[x] = max(massive_max[x * 2], massive_max[x * 2 + 1]);
    }
}

int get_min(int left, int right, int lx, int rx, int x){
    if(lx >= right || rx <= left){
        return INT_MAX;
    }
    if(left >= lx and right <= rx){
        return massive_min[x];
    }

    int middle = (right + left) / 2;
    int min1 = get_min(left, middle, lx, rx, x * 2);
    int min2 = get_min(middle, right, lx, rx, x * 2 + 1);
    return min(min1, min2);
}

int get_max(int left, int right, int lx, int rx, int x){
    if(lx >= right || rx <= left){
        return INT_MIN;
    }
    if(left >= lx and right <= rx){
        return massive_max[x];
    }

    int middle = (right + left) / 2;
    int max1 = get_max(left, middle, lx, rx, x * 2);
    int max2 = get_max(middle, right, lx, rx, x * 2 + 1);
    return max(max1, max2);
}

signed main(){
    
    goodluck
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
   

    for(int i = 1; i < 200100; i++){
        massive[i] = (i * i) % 12345 + (i * i * i) % 23456; 
    }
    // for(int i = 1; i < 4; i++) cout << massive[i] << " "; cout << ENDL;
    create_max(1, 200100, 1);
    create_min(1, 200100, 1);
    
    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        if(l < 0){
            set_min(1, 200100, 1, -l, r);
            set_max(1, 200100, 1, -l, r);
        } else{
            cout << get_max(1, 200100, l, r + 1, 1) - get_min(1, 200100, l, r + 1, 1) << ENDL;
        }
    }
    




    endd
}