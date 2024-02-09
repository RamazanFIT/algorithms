#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    set<int> check;
    int w[n];
    for(int i = 0; i < n; i++){
        cin >>w[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            check.insert(w[i] + w[j]);
        }
    }
    int m;
    cin >> m;
    for(int i = 0 ;i < m; i++){
        int a;cin>>a;
        if(check.find(a) != check.end()){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}