#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int kmp(string s, string a){
    int size = a.size();

    a = a + "#" + s;

    vector<int> prefixfunc(a.size());
    int pointer = 0;
    int i = 1;
    int max_el = 0;
    
    while(i < a.size()){
        if(a[pointer] == a[i]){
            pointer++;
            prefixfunc[i] = pointer;
            i++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunc[pointer - 1];
        }
    }
    return prefixfunc[a.size() - 1];
    
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    string s;
    cin >> s;
    s[0] = _tolower(s[0]);
    int n;
    cin >> n;
    vector<pair<string, int> > auth;
    int max_el = 0;
    while(n--){
        string a;
        cin >> a;
        a[0] = _tolower(a[0]);

        int cnt = kmp(s, a);
        max_el = max(max_el, cnt);
        auth.push_back(make_pair(a, cnt));
    }
    // cout << auth.size() << ENDL;
    queue<string> q;
    for(auto it : auth){
        if(max_el == 0) break;
        if(it.second == max_el){
            // cout << it.first << ENDL;
            // q.push()
            string tmp = it.first;
            tmp[0] = _toupper(tmp[0]);
            q.push(tmp);
        }
        // cout << it.first << " " << it.second << ENDL;
    }
    cout << q.size() << ENDL;
    while(!q.empty()){
        cout << q.front() << ENDL;
        q.pop();
    }


    endd
}