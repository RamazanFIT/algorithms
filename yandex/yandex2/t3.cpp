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
vector<vector<pair<int, int>>> g;
void solve(int ccase){
    int n, m;get(n, m);
    g = vector<vector<pair<int, int>>>(n + 2);

    repeat(m){
        int x, y, cost;
        get(x, y, cost);
        g[x].pb({y, cost});
        g[y].pb({x, cost});
    }   

    int k;get(k);
    // x, y, t, c 
    vector<pair<int, pair<pair<int, int>, pair<int, int>>>> v;
    repeat(k){
        int x, y, t, c;get(x, y, t, c);
        v.pb({c, {{x, y}, {_ + 1, t}}});
    }
    sort(all(v));

    set<int> check;

    int pp;get(pp);

    map<pair<int, int>, int> mapa;
    map<pair<int, int>, int> mapa2;
    repeat(pp){
        int x, y, c;
        get(x, y, c);
        mapa[{x, y}] = c;
        mapa[{y, x}] = c;
        // check.insert(x);
        // check.insert(y); r_syrlybay
    }
    if(true){
        vvi cost(n + 1, vii(n + 1));

        for(int start = 1; start <= n; start++){
            int s = start;
 
            vector<int> d (n + 1, INT_MAX / 2),  p (n + 1);
            d[s] = 0;
            set < pair<int,int> > q;
            q.insert (make_pair (d[s], s));
            while (!q.empty()) {
                int v = q.begin()->second;
                q.erase (q.begin());
        
                // for (size_t j=0; j<g[v].size(); ++j) {
                for(auto vv:g[v]){
                    // int to = g[v][j].first,
                    //     len = g[v][j].second;
                    int to = vv.ff;
                    int len = vv.ss;
                    if (d[v] + len < d[to]) {
                        q.erase (make_pair (d[to], to));
                        d[to] = d[v] + len;
                        p[to] = v;
                        q.insert (make_pair (d[to], to));
                    }
                }
            }
            cost[start] = d;
        }
        bool flag = true;
        for(auto iter:mapa){
            int x, y, c;
            x = iter.first.first;
            y = iter.first.second;
            c = iter.second;
            if(cost[x][y] > c){
                flag = false;
                mapa2[{x, y}] = c;
            }
        }
        if(flag){
            cout << 0;
            return;
        }
    }
    vii ans;
    int cnt = 0;
    for(auto it : v){
        if(cnt > 2500){
            cout << -1;
            return;
        }
        int x, y, t, i;
        x = it.ss.ff.ff;
        y = it.ss.ff.ss;
        i = it.ss.ss.ff;
        t = it.ss.ss.ss;
        g[x].pb({y, t});
        g[y].pb({x, t});
        
        vvi cost(n + 1, vii(n + 1));

        for(int start = 1; start <= n; start++){
            int s = start;
 
            vector<int> d (n + 2, INT_MAX),  p (n + 2);
            d[s] = 0;
            set < pair<int,int> > q;
            q.insert (make_pair (d[s], s));
            while (!q.empty()) {
                int v = q.begin()->second;
                q.erase (q.begin());
        
                for(auto vv:g[v]){
                    // int to = g[v][j].first,
                    //     len = g[v][j].second;
                    int to = vv.ff;
                    int len = vv.ss;
                    if (d[v] + len < d[to]) {
                        q.erase (make_pair (d[to], to));
                        d[to] = d[v] + len;
                        p[to] = v;
                        q.insert (make_pair (d[to], to));
                    }
                }
            }
            cost[start] = d;
        }
        bool flag = true;
        map<pair<int, int>, int> mapa3;

        for(auto iter:mapa2){
            int x, y, c;
            x = iter.first.first;
            y = iter.first.second;
            c = iter.second;
            if(cost[x][y] > c){
                flag = false;
                mapa3[{x, y}] = c;
            }
        }
        ans.push_back(i);
        if(flag){
            sort(all(ans));
            cout << ans.size() << ENDL;
            for(auto ittt: ans){
                cout << ittt << " ";
            
            }
            return;
        }
        mapa2 = *(&mapa3);
    }
    cout << -1 << ENDL;


    
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