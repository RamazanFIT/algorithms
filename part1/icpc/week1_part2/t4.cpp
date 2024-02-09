#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define ull ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;

int n;
int power;
int C = 10000001;
int c;

// int rec(){
//     if(n == 0) return 0;
//     int k = 1;
//     int result = 0;
//     while(k <= n){
//         result = (result + (k * c) % t) % t;
//         n -= k;
//         k *= 2;
//     }
//     if(n == 0) return result;
//     else return result + rec();

// }

// int rec2(int a, int b){

//     if(a == 0) return 0;
//     int k = 1;
//     int result = 0;
//     while(k <= a){
//         result = (result + (k * b) % t) % t;
//         a -= k;
//         k *= 2;
//     }
//     if(a == 0) return result;
//     else return result + rec2(a, b);

// }

ull binsum(ull x, ull y){
    if (y==1)
    return x%C;
    ull dbld=((binsum(x, y/2)%C) * (2%C) )%C ;
    ull adtn=( (x%C) * (y%2))% C;
    return (dbld%C+adtn%C)%C;

}





int binpow(int x, int y){
    if (y==0)
    return 111%C;
    if(y==1)
    return x%C;
    int ans=binpow (x%C, y/2) ;
    if (y%2==0){
    return ((ans%C)* (ans%C))%C;
    } else{
    return ((((ans%C)* (ans%C) )%C) * (x%C) ) %C;
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    // cin >> n;
    // c = n;
    // cout << rec();
    
    int a, b;
    cin >> a >> b;
    cout << binsum(a, b);

    endd
}