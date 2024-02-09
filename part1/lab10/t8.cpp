#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    // kmp 
    string s; cin >> s;
    vector<int> prefixfuntion(s.size());    
    int pointer = 0; int i = 0;
    while(i < s.size()){
        if(s[i] == s[pointer]){
            prefixfuntion[i++] = ++pointer;
        } else if(pointer == 0) prefixfuntion[i] = pointer;
        else pointer = prefixfuntion[pointer];
    }
    


    endd
}