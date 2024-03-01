// Bismillah 
// لا إله إلا الله محمد رسول الله
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define print(massive) for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;
vii d;
#define M (xl + xr) / 2
#define L 2 * x + 1
#define R L + 1
#define LL xl, M
#define RR M, xr

vii mass;

struct save{
    int sum = 0;
    int sqrt_sum = 0;
    int pi = 1;
};

vector<save> t;

void build(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x].sum = mass[xl];
        t[x].sqrt_sum = sqrt(mass[xl]);
    }
}



void solve(int ccase){
    int n;
    cin >> n;

    repeat(n) cin >> mass[_];
    

    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}