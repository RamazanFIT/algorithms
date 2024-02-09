#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    list<int> some_list;
    some_list.push_front(1);
    some_list.push_front(2);
    some_list.pop_back(); 
    some_list.push_back(122);   
    auto it = some_list.begin();
    it++;
    some_list.insert(it, 10);
    for(auto i : some_list){
        cout << i << " ";
    }
    
    
    


    endd
}