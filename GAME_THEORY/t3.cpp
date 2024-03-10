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
vii mass;
vii res;
int mex(int n){
    set<int> st;
    for(int i = 1; i < n % 2 + n / 2; i++){
        st.insert((mass[i] ^ mass[n - i]));
    }

    int cnt = 0;
    while(st.find(cnt) != st.end()){
        cnt++;
    }
    return cnt;
}

void solve(int ccase){
    int n;
    get(n)
    
    int x = 1;
    if(n < 1300){
        x = mass[n];
    }
    if(x != 0) cout << res[n] << ENDL;
    else cout << 0 << ENDL;
}

signed main(){
    
    goodluck 
    
    int N = 10001; 
    res = mass = vii(N);

    for(int i = 1; i < N; i++){
        mass[i] = mex(i);
    }

    for(int i = 1; i < N; i++){
        int cnt = 0;
        for(int j = 1; j < i % 2 + i / 2; j++){
            if(!(mass[j] ^ mass[i - j])) cnt++;
        }
        res[i] = cnt;
    }
    
    int t = 1;
    cin >> t;
    repeat(t) solve(_);
    

    endd
}