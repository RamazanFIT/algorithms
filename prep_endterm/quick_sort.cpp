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


int partition(vector<int> & massive, int left, int right){
    int pivot = rand() % (right - left + 1) + left;
    int last = left - 1;
    swap(massive[pivot], massive[right]);
    for(int i = left; i < right; i++){
        if(massive[i] < massive[right]){
            swap(massive[++last], massive[i]);
        }
    }
    swap(massive[++last], massive[right]);
    return last;
}

void my_quick_sort(vector<int> & massive, int left, int right){
    if(left >= right) return;
    int pivot = partition(massive, left, right);
    my_quick_sort(massive, left, pivot - 1);
    my_quick_sort(massive, pivot + 1, right);
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++) cin >> massive[i];
    my_quick_sort(massive, 0, n - 1);
    for(auto it : massive) cout << it << " ";

    endd
    // bad  n * n 
    // best n * log n 
}