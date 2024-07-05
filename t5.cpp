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

vector<int> r, p, d;

int get(int a){
    if(a != p[a]){
        int next = p[a];
        p[a] = get(p[a]);
        if(p[a] != next)
        r[a] += r[next];
    } 
    return p[a];
    
}

int cnt = 0;

void join(int a, int b){
    a = get(a);
    b = get(b);

    if(a == b) return;

    if(d[a] > d[b]){
        swap(a, b);
    }

    // p[a] = b;
    p[a] = p[b] = p[cnt];
    d[cnt] = d[a] + d[b];
    cnt++;
}

void add(int a, int v){
    a = get(a);
    r[a] += v;
}

void solve(int ccase){

    int n, m;cin>>n>>m;
    d = r = p = vector<int>(2 * (n + m) + 2);
    cnt = n + m;
    for(int i = 1; i < 2 * (n + m) + 2; i++){
        p[i] = i;
        d[i] = 1;
    }

    for(int i = 0; i < m; i++){
        string s;cin >> s;
        
        
        if(s[0] == 'a'){
            int a, b;cin >> a >> b;
            add(a, b);
        } else if(s[0] == 'j'){
            int a, b;cin >> a >> b;
            join(a, b);
        } else{
            int a;
            cin >> a;
            int parent = get(a);
            if(parent != a)
            cout << r[parent] + r[a] << ENDL;
            else cout << r[parent] << ENDL;
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