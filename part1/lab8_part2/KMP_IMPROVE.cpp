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

    string s;
    cin >> s;
    string a;
    cin >> a;
    int size = a.size();
    a = a +  "#" +  s;
    // a < s 

    vector<int> prefixfunction(a.size());
    int pointer = 0;
    int i = 1;

    while(i < a.size()){
        if(a[pointer] == a[i]){
            prefixfunction[i] = pointer + 1;
            i++;
            pointer++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunction[pointer - 1];
        }
    }
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        
        if(prefixfunction[i] == size){
            cnt++;
        }
       
        
    }
    cout << cnt << ENDL;
    
    
    


    endd
}