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

int kmp(string s, string a){
    s = a + "#" + s;
    vector<int> prefixfunction(s.size());
    int last = 0;
    int i = 1;
    while(i < s.size()){
        if(s[i] == s[last]){
            prefixfunction[i] = last + 1;
            last++;
            i++;
        } else if(last == 0){
            i++;
        } else{
            last = prefixfunction[last - 1];
        }
    }
    int ans = 0;
    for(int i = a.size(); i < s.size(); i++){
        if(a.size() == prefixfunction[i]) ans++;
    }
    return ans;
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s, a;
    cin >> s >> a;
    cout << kmp(s, a);
    // O(n + m) 
    endd
}