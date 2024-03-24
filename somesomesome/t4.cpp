/* 
    Bismillah 
 لا إله إلا الله محمد رسول الله
 Al'-Phatixa
 بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 ٱلْحَمْدُ لِلَّهِ رَبِّ ٱلْعَٰلَمِينَ
 ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 مَٰلِكِ يَوْمِ ٱلدِّينِ
 إِيَّاكَ نَعْبُدُ وَإِيَّاكَ نَسْتَعِينُ
 ٱهْدِنَا ٱلصِّرَٰطَ ٱلْمُسْتَقِيمَ
 صِرَٰطَ ٱلَّذِينَ أَنْعَمْتَ عَلَيْهِمْ غَيْرِ ٱلْمَغْضُوبِ عَلَيْهِمْ وَلَا ٱلضَّآلِّينَ
*/
#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endd return 0;
#define repeat(x) for(int _ = 0; _ < x; _++)
#define vii vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define FORW(leftb,rightb,way) for(int i = leftb; i < rightb; i+=way)
#define FOR(leftb,rightb) for(int i = leftb; i < rightb; i+=1)
#define print(massive) \
    for(int i = 0; i < massive.size(); i++) cout << massive[i] << " ";
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define get(a) cin >> a;

using ll = unsigned long long;
using namespace std;

vii t;

vii d;


vii massive;

#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M
#define RR M, xr

void build1(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl];
        return;
    } 
    build1(L, LL);
    build1(R, RR);

    t[x] = gcd(t[R], t[L]);
}

void build2(int x, int xl, int xr){
    if(xr - xl == 1){
        d[x] = massive[xl];
        return;
    } 
    build2(L, LL);
    build2(R, RR);

    d[x] = lcm(d[R], d[L]);
}

int get1(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 0;

    if(xl >= l and xr <= r) return t[x];

    return gcd(get1(l, r, L, LL), get1(l, r, R, RR));
}

int get2(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 1;

    if(xl >= l and xr <= r) return d[x];

    return lcm(get2(l, r, L, LL), get2(l, r, R, RR));
}

void change1(int i, int v, int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = v;
        return;
    }
    if(i < M){
        change1(i, v, L, LL);
    } else{
        change1(i, v, R, RR);
    }
    t[x] = gcd(t[R], t[L]);
}

void change2(int i, int v, int x, int xl, int xr){
    if(xr - xl == 1){
        d[x] = v;
        return;
    }
    if(i < M){
        change2(i, v, L, LL);
    } else{
        change2(i, v, R, RR);
    }
    d[x] = lcm(d[R], d[L]);
}


void solve(int ccase){
    int n;
    cin >> n;
    massive = vii(n);
    t = d = vii(4 * (n + 1));

    repeat(n) cin >> massive[_];

    build1(0, 0, n);
    build2(0, 0, n);

    int q;
    cin >> q;
    repeat(q){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1){
            int y = get1(l - 1, r, 0, 0, n);
            int x = get2(l - 1, r, 0, 0, n);
            // cout << x << " " << y << ENDL;
            // cout << x << ENDL;
            if(x > y){
                cout << "wins" << ENDL;
            } else if(x < y){
                cout << "loser" << ENDL;

            } else{
                cout << "draw" << ENDL;
                
            }
        } else{
            change1(l - 1, r, 0, 0, n);
            change2(l - 1, r, 0, 0, n);
        }
    }

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