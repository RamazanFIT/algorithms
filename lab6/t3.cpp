#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define int ll
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = unsigned long long;
using namespace std;


bool comp(pair<double, pair<string, string> > a, pair<double, pair<string, string> > b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    if(a.second.first < b.second.first) return true;
    else  if(a.second.first > b.second.first) return false;
    if(a.second.second < b.second.second) return true;
    else  if(a.second.second > b.second.second) return false;
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    map<string, double> grades;
    //     {"A+", 4.00},
    //     {"A", 3.75},
    //     {"B+",	3.50},
    //     {"B",	3.00},
    //     {"C+",	2.50},
    //     {"C",	2.00},
    //     {"D+",	1.50},
    //     {"D",	1.00},
    //     {"F", 0}
    // };
    grades["A+"] = 4.00;
    grades["A"] = 3.75;
    grades["B+"] = 3.50;
    grades["B"] = 3.00;
    grades["C+"] = 2.50;
    grades["C"] = 2.00;
    grades["D+"] = 1.50;
    grades["D"] = 1.00;
    grades["F"] = 0.00;

    // map<double, string> mapa;
    vector<pair<double, pair<string, string> > > mapa;
    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        int k;
        cin >> k;
        double credits = 0;
        double sverxu = 0;
        for(int i = 0; i < k; i++){
            string a;
            cin >> a;
            double x;
            cin >> x;
            credits += x;
            sverxu += grades[a] * x;
        }
        // mapa[sverxu / credits] = (s1 + " " + s2);
        mapa.push_back(make_pair(sverxu / credits, make_pair(s1, s2)));
    }
    sort(all(mapa), comp);
    for(auto it : mapa){
        // cout << it.second.first << " " << it.second.second << " " << int(it.first) << '.';
        // int x = (it.first - double(int(it.first))) * 10000000000000000000;
        // if(x % 10000000000000000 >= int(10000000000000000 / 2)){
        //     x /= 10000000000000000;
        //     x++;
        // } else{
        //     x /= 10000000000000000;
        // }
        // int size = 0;
        // int copy = x;
        // while(copy > 0){
        //     size++;
        //     copy/=10;
        // }
        // for(int i = 0; i < 3 - size; i++) cout << '0';
        // if(x != 0)
        // cout << x << ENDL;
        // else cout << ENDL;
        cout << it.second.first << " " << it.second.second << " " << fixed << setprecision(3) << it.first << ENDL;
    }
    
    


    endd
}