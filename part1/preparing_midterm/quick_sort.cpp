#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int partition(vector<int> & massive, int left, int right){
    int middle = (left + right) / 2;
    swap(massive[middle], massive[right]);
    int index = left - 1;
    for(int i = left; i < right; i++){
        if(massive[i] <= massive[right]){
            index++;
            swap(massive[index], massive[i]);
        }
    }
    swap(massive[index + 1], massive[right]);
    return index + 1;
}


void quick_sort(vector<int> & massive, int left, int right){
    if(left >= right) return;
    int j = partition(massive, left, right);
    quick_sort(massive, left, j - 1);
    quick_sort(massive, j + 1, right);
    
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n = 10;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        massive[i] = n - i + 1000;
    }
    
    quick_sort(massive, 0, n - 1);

    for(int i = 0; i < n;i++){
        cout << massive[i] << " ";
    }
    


    endd
}