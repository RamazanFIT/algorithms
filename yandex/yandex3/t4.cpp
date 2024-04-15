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
#define int long long
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

char s[102][102];
int empty1, res, a, b, c, i, j, n, m;
vvi g;
vii mt, used, par;

int dfs(int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            par[v] = to;
            return 1;
        }
    }
    return 0;
}

void auth() {
    int run;
    mt.assign(n * m, -1);
    par.assign(n * m, -1);
    for (run = 1; run;) {
        run = 0; 
        used.assign(n * m, 0);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if ((i + j) % 2) continue;
                if (par[i * m + j] == -1 && dfs(i * m + j)) run = 1;
            }
        }
    }
}

void solve(int ccase){
    cin >> n >> m >> a >> b;
    for (i = 0; i < n; i++) cin >> s[i];
    g.resize(n*m); empty1 = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '.') continue;
            empty1++;
            if ((i + j) % 2) continue;
            int u = i*m + j;
            if (j && s[i][j - 1] == '*') g[u].push_back(u - 1); // left
            if (j < m - 1 && s[i][j + 1] == '*') g[u].push_back(u + 1); // right
            if (i && s[i - 1][j] == '*') g[u].push_back(u - m); // up
            if (i < n - 1 && s[i + 1][j] == '*') g[u].push_back(u + m); // down
        }
    }
    if (2 * b <= a) {
        cout << empty1 * b << endl;
        return;
    }
    auth();
    for (c = i = 0; i < n * m; i++) if (mt[i] != -1) c++;
    res = c * a + (empty1 - 2 * c) * b;
    cout << res << endl;
}

signed main(){
    goodluck
    int t = 1;
    repeat(t) solve(_);
    endd
}
