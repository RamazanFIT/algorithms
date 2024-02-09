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

bool check(vector<int>& massive, int & k, int minimum_of_maximum){
    int some_sum = 0;
    int group = 0;
    for(int i = 0; i < massive.size(); i++){
        if(massive[i] > minimum_of_maximum) return false; //--> это нужно, тк если один элемент в массиве будет
        some_sum += massive[i]; // больше чем самый минимальный из максимальных то его невозможно разделить
        if(some_sum > minimum_of_maximum){ // в 2 группы и он не уместиться поэтому мы должны увеличить размер нашего минимума.
            group++;
            some_sum = massive[i];
        }
    }
    group++;
    return group <= k;
}



signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    int left = 0;
    int right = __LONG_LONG_MAX__;
    int ans = __LONG_LONG_MAX__;
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(check(massive, k, mid)){
            ans = min(ans, mid);
            right = mid;
        } else{
            left = mid;
        }
    }
    cout << ans << ENDL;
    

    endd
}