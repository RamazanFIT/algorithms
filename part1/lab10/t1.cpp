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

void kmp(string s){
    vector<int> prefixfunction(s.size(), 0);
    int pointer = 0;
    int i = 1;

    // for(int i = 0; i < s.size(); i++){
    //     cout << s[i] << " ";
    // } cout << ENDL;;;;;;;;;
    while(i < s.size()){
        if(s[i] == s[pointer]){
            pointer++;
            prefixfunction[i] = pointer;
            i++;
        } else if(pointer == 0){
            prefixfunction[i] = pointer;
            i++;
        } else{
            pointer = prefixfunction[pointer - 1];
        }
    }
    // for(int i = 0; i < s.size(); i++){
    //     cout << prefixfunction[i] << " ";
    // }
    int cnt = 0;
    unordered_set<int> check;
    int f = 0;
    if(s.size() % 2 != 0){
        f++;
    }
    for(int i = 0; i < s.size(); i++){
        if(prefixfunction[i] != 0 and prefixfunction[i] < (s.size() / 2 +f) and check.find(prefixfunction[i]) == check.end()){
            bool flag = true;
            for(int j = 0; j < prefixfunction[i]; j++){
                if(prefixfunction[i] + j >= s.size()){
                    flag = false;
                    break;
                }
                if(s[j] != s[prefixfunction[i] + j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
            check.insert(prefixfunction[i]);
        }
    }
    cout << cnt << ENDL;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s;
    cin >> s;
    
    kmp(s);
    

    endd
}