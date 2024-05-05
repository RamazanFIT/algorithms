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


struct point{
    double x, y;
};

double getPolygonS(vector<point> massive, point a){
    massive.pb(a);
    double ans = 0;
    for(int i = 1; i < massive.size(); i++){
        double x1, x2, y1, y2;
        x1 = massive[i - 1].x;
        x2 = massive[i].x;
        y1 = massive[i - 1].y;
        y2 = massive[i].y;
        ans += (y1 + y2) * (x2 - x1);
    }
    ans += (massive[massive.size() - 1].y + massive[0].y) * (massive[0].x - massive[massive.size() - 1].x);
    return ans; //со знаком
}



bool insertectProjection(double a, double b, double c, double d){
    if(a > b) swap(a, b);
    if(c > d) swap(c, d); // чтобы просто правильно поставить на место отрезки

    return max(a, c) <= min(b, d);
}

bool checkOnSegment(vector<point> &f, vector<point> &s){

    bool flag = getPolygonS(f, s[0]) * getPolygonS(f, s[1]) <= 0 
            && 
            getPolygonS(s, f[0]) * getPolygonS(s, f[1]) <= 0
            &&
            insertectProjection(f[0].x, f[1].x, s[0].x, s[1].x)
            && 
            insertectProjection(f[0].y, f[1].y, s[0].y, s[1].y);
    return flag;

}

void solve(int ccase){
    
    int n;
    get(n);
    // n = ccase;

    vector<point> polygon(n);
    repeat(n) get(polygon[_].x, polygon[_].y);
    
    int k;get(k);

    // point someP;
    // get(someP.x, someP.y);
    vector<point> points(k);
    repeat(k) get(points[_].x, points[_].y);
    
    polygon.pb(polygon[0]);

    repeat(k){
        bool flag = false;
        point someP = points[_];
        for(int i = 1; i <= n; i++){
            vector<point> tmp1;
            vector<point> tmp2;
            tmp1.pb(polygon[i]);
            tmp1.pb(polygon[i - 1]);
            tmp2.pb(someP);
            tmp2.pb(someP);
            if(checkOnSegment(tmp1, tmp2)){
                put("BORDER", ENDL);
                flag = true;
                break;
            }
        }
        if(flag) continue;
        for(int i = 1; i < polygon.size();i++){

            double maxx = 1;
            double minn = 1;
            vector<point> tmp;
            tmp.pb(polygon[i]);
            tmp.pb(polygon[i - 1]);
            double S = getPolygonS(tmp, someP);
            
            maxx = max(maxx, S);
            minn = min(minn, S);

            if(maxx*minn < 0){
                put("OUTSIDE", ENDL);
                flag = true;
                break;
            }
        }
        if(flag) continue;
        put("INSIDE", ENDL);
    }
    
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int t = 1;
    // cin >> t;
    repeat(t) solve(_);
    // int t;
    // while(cin >> t){
    //     if(t == 0) endd 
    //     solve(t);
    // }

    endd
}