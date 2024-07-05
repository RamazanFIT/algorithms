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

vii p, r;

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
    if(r[a] > r[b]){
        swap(a, b);
    }

    r[b] += r[a];

    p[a] = b;

}

void solve(int ccase){
    int n, m;
    cin >> n >> m;

    p = vii(n + 1);
    r = vii(n + 1, 1);

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    int cnt = n;
    int maxx = 1;
    
    repeat(m){
        int a, b;cin>>a>>b;
        
        if(get(a) != get(b)){
            cnt--;
        }
        join(a, b);
        maxx = max(maxx, r[get(a)]);

        cout << cnt << " " << maxx << ENDL;

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