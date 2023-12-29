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
    int first = 0;
    int last = 0;
    bool flag = true;
    bool f = false;
    for(int i = size; i < a.size(); i++) cout << a[i] << " "; cout << ENDL;
    for(int i = size; i < a.size(); i++){
        
        // if(prefixfunction[i] == size){
        //     cnt++;
        //     if(flag){
        //         first = i - a.size();
        //         flag = false;
        //     }
        //     last = i;
        // }
        // if(f){
        //     if(!prefixfunction[i]){
        //         cout << - 1;
        //         exit(0);
        //     }
        // }
        cout << prefixfunction[i] << " ";
     
        // if(prefixfunction[i]){
        //     f = true;
        // }
    }
    if(first != 0){
        cnt++;
    }
    if(last != a.size() - 1){
        cnt++;
    }
    cout << cnt << ENDL;
    exit(0);
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string a, b;
    cin >> a >> b;
    if(b.size() <= a.size()){
        if(a.find(b) != -1){
            cout << 1;
            return 0;
        }
    }
    kmp(b, a);
    


    endd
}