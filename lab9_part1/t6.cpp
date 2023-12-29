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
    int size = a.size();

    a = a + "#" + s;

    vector<int> prefixfunc(a.size());
    int pointer = 0;
    int i = 1;

    vector<int> ans;
    while(i < a.size()){
        if(a[pointer] == a[i]){
            pointer++;
            prefixfunc[i] = pointer;
            if(prefixfunc[i] == size){
                ans.push_back(i - 2 * size + 1);
            }
            i++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunc[pointer - 1];
        }
    }
    cout << ans.size() << ENDL;
    for(auto it : ans) cout << it << " ";
    
    
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