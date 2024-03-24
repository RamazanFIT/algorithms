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

using ll = long long;
using namespace std;

#define L 2 * x + 1
#define R 2 * x + 2
#define M (xl + xr) / 2
#define LL xl, M 
#define RR M, xr 

struct node
{
    int prefix;
    int suffix;
    int ans;
    int sum;

    node(){

    }

    node(int prefix, int suffix, int ans, int sum){
        this->prefix = prefix;
        this->suffix = suffix;
        this->ans = ans;
        this->sum = sum;
    }
};

vector<node> t;
vii d, massive;

node combine(node a, node b){
    node c;
    c.sum = a.sum + b.sum;
    c.ans = max(max(a.ans, b.ans), a.suffix + b.prefix);
    c.prefix = max(a.prefix, a.sum + b.prefix);
    c.suffix = max(b.suffix, b.sum + a.suffix);
    return c;
}

void build(int xl, int xr, int x){
    if(xr - xl == 1){
        t[x] = node(massive[xl], massive[xl], massive[xl], massive[xl]);
        return;
    }
    build(LL, L);
    build(RR, R);
    t[x] = combine(t[L], t[R]);
}

void push(int xl, int xr, int x){
    if(d[x] != INT_MIN / 2){
        int v = d[x];
        // if(v >= 0){
            t[x].sum = (xr - xl) * v;
            t[x].prefix = (xr - xl) * v;
            t[x].suffix = (xr - xl) * v;
            t[x].ans = t[x].sum;
        // } else{
        //     t[x].ans = 0;
        //     t[x].sum = 0;
        //     t[x].prefix = 0;
        //     t[x].suffix = 0;
        // }
    }
}
int f = 11;
void change(int l, int r, int v, int x, int xl, int xr){

    
    if(xl >= r or xr <= l) return;
    if(xl >= l and xr <= r){
        // if(v >= 0){
            t[x].sum = (xr - xl) * v;
            t[x].prefix = (xr - xl) * v;
            t[x].suffix = (xr - xl) * v;
            t[x].ans = t[x].sum;
        // } else{
        //     t[x].ans = 0;
        //     t[x].sum = 0;
        //     t[x].prefix = 0;
        //     t[x].suffix = 0;
        // }
        d[x] = v;
        return;
    }
    if(d[x] != INT_MIN / 2){
        d[L] = d[x];
        d[R] = d[x];
        push(LL, L); 
        push(RR, R);
        d[x] = INT_MIN / 2;
    }
    change(l, r, v, L, LL);
    change(l, r, v, R, RR);

    t[x] = combine(t[L], t[R]);
    
}

node getmaxsum(int l, int r, int x, int xl, int xr){
    if(xl >= r or xr <= l) return node(0, 0, 0, 0);
    if(xl >= l and xr <= r){
        return t[x];
    }
    if(d[x] != INT_MIN / 2){
        push(LL, L);
        push(RR, R);
        d[R] = d[x];
        d[L] = d[x];
        d[x] = INT_MIN / 2;
    }

    return combine(getmaxsum(l, r, L, LL), getmaxsum(l, r, R, RR));

}

void printTree(int x, int maxn, int tab){
    if(x >= maxn) return;
    printTree(R, maxn, tab + 4);
    repeat(tab) cout << "| "; cout << "(" <<  x << "," << t[x].ans <<"," << t[x].prefix <<"," << t[x].suffix << "," << d[x] << ")" << ENDL;
    printTree(L, maxn, tab + 4);
}

void solve(int ccase){
    int n, q;
    cin >> n >> q;
    // node(INT_MIN / 2, INT_MIN / 2, INT_MIN / 2, 0)
    t = vector<node>(4 * (n + 1), node(0, 0, 0, 0));
    d = vii(4 * (n + 1), INT_MIN / 2);
    // massive = vii(n);
    // repeat(n){
    //     cin >> massive[_];
    // }
    // build(0, n, 0);


    repeat(q){
        // int t;
        // cin >> t;
        int l, r, v;
        // change(l, r, v, 0, 0, n);
        // 
        // cout << getmaxsum()
        // node a = getmaxsum(0, n, 0, 0, n);
        // cout << a.ans << ENDL;
        // if(t == 1){
        cin >> l >> r >> v;
        change(l, r, v, 0, 0, n);

        // } else if(t == 2){

        node a = getmaxsum(0, n, 0, 0, n);
        cout << max(a.ans, 0ll) << ENDL;

        // } else{
        //     printTree(0, 4 * (n + 1), 0);
        // }

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