#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


void kmp(string s, string a){
    string copy_s = s, copy_a = a;
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
   
    string hhh = "";
    for(int i = max_el; i < copy_a.size(); i++){
        hhh += copy_a[i];
    }
    for(int i = 0; i < max_el; i++){
        hhh += copy_a[i];
    }
    if(hhh != copy_s){
        cout << -1 << ENDL;
        exit(0);
    } else{
        cout << max_el % copy_a.size() << ENDL;
    }
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string a, s;
    cin >> s >> a;
    kmp(s, a);
    


    endd
}