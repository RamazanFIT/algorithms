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

    int n;
    cin >> n;
    if(n == 1){

        string s;
        cin >> s;
        cout << s;
        return 0;
    }
    
    string a;
    string b;
    string tmpp;
    cin >> a >> b;
    for(int i = 0; i < b.size(); i++){
        int j = 0;
        string tmp;
        while(j < a.size()){
            if(tmp.size() < tmpp.size()) tmpp = tmp;
            if(a[j] == b[i]){
                tmp += a[j];
                i++;
            } else{
                tmp = "";
            }
            j++;
        }
    }
    cout << tmpp;


    endd
}