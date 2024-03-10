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
const int N = 1001;
vii mass = vii(N);

int mex(set<int> a){
    int cnt = 0;
    while(a.find(cnt) != a.end()){
        cnt++;
    }
    return cnt;
}

void solve(int ccase){
    int n;
    cin >> n;
    if(mass[n] != 0){
        cout << "1" << ENDL;
    } else{
        cout << "2" << ENDL;
    }
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int q = 3;
    mass[1] = 1;
    mass[2] = 2;
    mass[3] = 0;
    for(int i = 4; i < N; i++){
        if(i % q == 1){
            set<int> a;
            a.insert(mass[i - 1]);
            a.insert(mass[i - 3]);
            mass[i] = mex(a);
        } else if(i % q == 2){
            set<int> a;
            a.insert(mass[i - 1]);
            a.insert(mass[i - 2]);
            a.insert(mass[i - 3]);
            mass[i] = mex(a);
        } else{
            set<int> a;
            a.insert(mass[i - 1]);
            a.insert(mass[i - 2]);
            mass[i] = mex(a);
        }
    }

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    

    endd
}