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

#define MAX 301

 
int g[MAX][MAX];
vector<int> used, par, mt;
int i, j, ptr;
int rows, cols, cuts, a, b, flow;
 
int dfs(int v)
{
  if (used[v]) return 0;
  used[v] = 1;
  for (int to = 0; to < cols; to++)
  {
    if (g[v][to] == 0) continue;
    if (mt[to] == -1 || dfs(mt[to]))
    {
      mt[to] = v;
      par[v] = 1;
      return 1;
    }
  }
  return 0;
}
 
void AugmentingPath()
{
  int i, run;
  mt.assign (cols, -1);
  par.assign (rows, -1);
 
  for (run = 1; run; )
  {
    run = 0; used.assign(rows, 0);
    for (i = 0; i < rows; i++)
      if ((par[i] == -1) && dfs(i)) run = 1;
  }
}
 

void solve(int ccase){

    for(i = 0; i < rows; i++)
    for(j = 0; j < cols; j++) g[i][j] = 1;
 
    for(i = 0; i < cuts; i++)
    {
      get(a, b);
      g[a][b] = 0;
    }
 
    AugmentingPath();
 
    for (flow = i = 0; i < cols; i++)
      if (mt[i] != -1) flow++;
 

    put(flow, ENDL);
  
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);


    // // cin >> t;
    // repeat(t) solve(_);
    while(cin >> rows >> cols >> cuts) solve(0);

    endd
}