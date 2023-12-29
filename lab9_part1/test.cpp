#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
int kmp(string s, string a){
    int size = a.size();

    a = a + "#" + s;

    vector<int> prefixfunc(a.size());
    int pointer = 0;
    int i = 1;
    int max_el = 0;
    
    while(i < a.size()){
        if(a[pointer] == a[i]){
            pointer++;
            prefixfunc[i] = pointer;
            max_el = max(max_el, prefixfunc[i]);
            i++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunc[pointer - 1];
        }
    }
    // return max_el;
    for(auto it : prefixfunc) cout << it << " ";
    
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s, a;
    cin >> s >> a;
    kmp(s, a);
    


    endd
}