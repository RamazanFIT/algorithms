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
    // freopen("sdt.out", "w", stdout);

    queue <int16_t> st1;
    
    queue <int16_t> st2;

    int cnt = 0;

    for(int i = 0; i < 5; i++){
        int16_t a;
        cin>>a;
        st1.push(a);
    }
    for(int i = 0; i < 5; i++){
        int16_t a;
        cin>>a;
        st2.push(a);
    }
    
    while(true){
        
      
        if(st1.empty()){
            cout << "Nursik" << " " << cnt << ENDL;
            return 0;
        } else if(st2.empty()){
            cout << "Boris" << " " << cnt << ENDL;
        
            return 0;
        }
        if(st1.front() == 0 and st2.front() == 9){
            st1.push(st1.front());
            st1.pop();
            st1.push(st2.front());
            st2.pop();
        }
        else if(st1.front() == 9 and st2.front() == 0){
            st2.push(st1.front());
            st1.pop();
            st2.push(st2.front());
            st2.pop();
        } else
        if(st1.front() > st2.front()){
            st1.push(st1.front());
            st1.pop();
            st1.push(st2.front());
            st2.pop();
        } else{
            st2.push(st1.front());
            st1.pop();
            st2.push(st2.front());
            st2.pop();
        }
        cnt++;
    }

    endd
}