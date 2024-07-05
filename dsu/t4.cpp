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

using ll = long long;
using namespace std;

vector<int> p;

struct node{
    int maximum;
    int minimum;
    int r;

    node(){
        maximum = INT_MIN;
        minimum = INT_MAX;
        r = 0;
    }
};

vector<node> r;

int get(int a){
    if(a != p[a]){
        p[a] = get(p[a]);
    }
    return p[a];
}

void join(int a, int b){
    a = get(a);
    b = get(b);

    if(a == b) return;

    if(r[a].r > r[b].r){
        swap(a, b);
    }
    r[b].r += r[a].r;
    p[a] = b;
    r[b].maximum = max(r[b].maximum, r[a].maximum);
    r[b].minimum = min(r[b].minimum, r[a].minimum);
}


void solve(int ccase){
    int n, m;
    cin >> n >> m;
    p = vector<int>(n + 1);

    r = vector<node>(n + 1);

    for(int i = 1; i <= n; i++){
        p[i] = i;
        r[i].r = 1;
        r[i].maximum = i;
        r[i].minimum = i;
    }

    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;
        int a, b;


        if(s == "get"){
            cin >> a;
            a = get(a);
            cout << r[a].minimum << " " << r[a].maximum << " " << r[a].r << ENDL;
        } else{
            cin >> a >> b;
            join(a, b);
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