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
            // prefixfunction[i] = 0;
            i++;
        } else{
            pointer = prefixfunction[pointer - 1];
        }
    } // a.size() = m
    int j = 0; // for a
    i = 0; // for s
    while(i < s.size()){
        if(s[i] == a[j]){
            j++;
            i++;
        } else if(j == 0){
            i++;
        } else {
            j = prefixfunction[j - 1];
        }
        if(j == a.size()){
            cout << i - a.size() << " ";
            j = 0;
            
        }
    } // s.size() = n
    // O(n + m)
    


    endd
}