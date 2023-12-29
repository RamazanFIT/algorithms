#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

void merge_sort(vector<int> & massive, int left, int right){
    if(left >= right) return;
    int middle = (right + left) / 2;
    
    merge_sort(massive, left, middle);
    merge_sort(massive, middle + 1, right);

    vector<int> tmp;
    int i = left;
    int j = middle + 1;
    while(i <= middle and j <= right){
        if(massive[i] > massive[j]){
            tmp.push_back(massive[j]);
            j++;
        } else{
            tmp.push_back(massive[i]);
            i++;
        }
    }
    for(int k = i; k <= middle; k++){
        tmp.push_back(massive[k]);
    }
    for(int k = j; k <= right; k++){
        tmp.push_back(massive[k]);
    }
    int index = 0;
    for(int k = left; k <= right; k++){
        massive[k] = tmp[index];
        index++;
    }
    return;
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n = 10;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        massive[i] = n - i;
    }
    
    merge_sort(massive, 0, n - 1);

    for(int i = 0; i < n;i++){
        cout << massive[i] << " ";
    }


    endd
}