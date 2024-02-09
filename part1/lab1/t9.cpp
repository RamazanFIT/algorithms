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
    
    // goodluck
    // freopen("std.in", "r", stdin);
    // freopen("sdt.out", "w", stdout);

    deque<int> dq;
    while(true){
        int a;
        char c;
        cin >> c;
        
        if(c == '!') break;
        if(c == '+'){
            cin>>a;
            dq.push_front(a);
        } else if(c == '-'){
            cin>>a;
            dq.push_back(a);
        } else if(c == '*'){
            if(dq.empty()){
                cout << "error" << ENDL;

            } else{
                cout << dq.front() + dq.back() << ENDL;
                dq.pop_back();
                if(!dq.empty()) dq.pop_front();
            }
        } 
    }
    


    endd
}