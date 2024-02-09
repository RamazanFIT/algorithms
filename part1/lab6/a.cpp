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

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    map<char, int> yes_vowels;
    map<char, int> not_vowels;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        if(vowels.find(a) == vowels.end()){
            not_vowels[a]++;
        } else{
            yes_vowels[a]++;
        }
    }
    for(auto it : yes_vowels){
        for(int i = 0; i < it.second; i++) cout << it.first;
    }
    for(auto it : not_vowels){
        for(int i = 0; i < it.second; i++) cout << it.ff;
    }
    


    endd
}