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
    
    while(i < a.size()){
        if(a[pointer] == a[i]){
            pointer++;
            prefixfunc[i] = pointer;
            i++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunc[pointer - 1];
        }
    }
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(prefixfunc[i] == size){
            cnt++;
        }
    }
    return cnt;
    
}




signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int cnt;
    string a, s;
    cin >> a >> cnt;
    cin >> s;

    int cnt2 = kmp(s, a);
    if(cnt2 < cnt){
        cout << "NO" << ENDL;
    } else{
        cout << "YES" << ENDL;
    }
    // cout << cnt << " " << cnt2;
    


    endd
}