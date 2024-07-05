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
template<typename T>
void get(T &a) {std::cin >> a;}
template<typename T, typename... Args>
void get(T &a, Args&... args) {std::cin >> a;get(args...);}
template<typename T>
void put(const T &a) {std::cout << a;}
template<typename T, typename... Args>
void put(const T &a, const Args&... args) {std::cout << a;put(args...);}

using ll = long long;
using namespace std;

#define L 2 * x + 1
#define R L + 1
#define M (xl + xr) / 2
#define LL xl, M
#define RR M, xr 

vector<int> ttt;
vector<int> zero;
vector<int> massive;
vector<int> t;

void bu(int x, int xl, int xr){
    if(xr - xl == 1){
        ttt[x] = zero[xl];
        return;
    }
    bu(L, LL);
    bu(R, RR);
    ttt[x] = ttt[L] + ttt[R];
}

void buu(int x, int xl, int xr){
    if(xr - xl == 1){
        t[x] = massive[xl];
        return;
    }
    buu(L, LL);
    buu(R, RR);
    t[x] = max(t[L], t[R]);
}

int get_sum_0(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return 0;
    if(xl >= l and xr <= r){
        return ttt[x];
    }

    return get_sum_0(l, r, L, LL) + get_sum_0(l, r, R, RR);
}

int get(int l, int r, int x, int xl, int xr){
    if(xr <= l or xl >= r) return INT_MIN;

    if(xl >= l and xr <= r){
        return t[x];
    }

    return max(get(l, r, L, LL), get(l, r, R, RR));
}

int get_dist(vector<int> v, int i){
    return distance(v.begin(), lower_bound(all(v), i));
}

void solve(int ccase){
    int n; get(n);
    massive = vii(n);
    zero = vii(n);
    int q;get(q);
    vector<int> some0;
    repeat(n) {get(massive[_]);
    if(massive[_] == 0) {some0.pb(_);zero[_] = 1;}
    }
    t = vii(4 * (n + 1), INT_MIN);
    ttt = vii(4 * (n + 1));

    bu(0, 0, n);
    buu(0, 0, n);

    repeat(q){
        int l, r, v;get(l, r, v);
        if(get_sum_0(l - 1, r, 0, 0, n) >= 1){
            cout << "Yes" << ENDL;
            continue;
        }

        if(get_sum_0(0, l, 0, 0, n) > 0){
            int pos = (lower_bound(all(some0), l) - some0.begin());
            if(pos == 0){
                pos =1 ;
            }
            pos = some0[pos - 1];
            int maax = get(pos, l, 0, 0, n);
            // cout << "lmax" << maax << ENDL;

            if(v > maax and v > massive[l - 1]){
                cout << "Yes" << ENDL;
                continue;
            } 

        }

        
        if(get_sum_0(r - 1, n, 0, 0, n) > 0){
            int pos = (lower_bound(all(some0), r) - some0.begin());

            pos = some0[pos];
            int maax = get(r, pos, 0, 0, n);
            // cout << "rmax" << maax << ENDL;

            if(v > maax and v > massive[r - 1]){
                cout << "Yes" << ENDL;
                continue;
            } 

        }

        cout << "No" << ENDL;

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