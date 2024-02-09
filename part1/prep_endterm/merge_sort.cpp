#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void my_merge_sort(vector<int> & massive, int left, int right){
    if(left >= right) return;
    int middle = (left + right) / 2;
    vector<int> tmp;
    my_merge_sort(massive, left, middle);
    my_merge_sort(massive, middle + 1, right);
    int index_left = left;
    int index_right = middle + 1;
    while(true){
        if(index_left > middle) break;
        if(index_right > right) break;
        if(massive[index_left] > massive[index_right]){
            tmp.push_back(massive[index_right++]);
        } else{
            tmp.push_back(massive[index_left++]);
        }
    }
    for(int i = index_left; i <= middle; i++){
        tmp.push_back(massive[i]);
    }
    for(int i = index_right; i <= right; i++){
        tmp.push_back(massive[i]);
    }
    int to_give = 0;
    for(int i = left; i <= right; i++){
        massive[i] = tmp[to_give++];
    }
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    my_merge_sort(massive, 0, n - 1);
    for(auto it : massive) cout << it << " ";
    // BEST WORTH AVARAGE - O(n * log(n))
    endd
}