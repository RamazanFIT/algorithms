#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define ENDL "\n"
    #define ff first 
    #define ss second  
    #define pb push_back
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
    using ll = long long;


    bool isInterleave(string s1, string s2, string s3) {
        // cout << "HEllo ";
        
        set<string> check;

        for(int ls = 1; ls <= s1.size(); ls++){
            
            if(s1.size() % ls != 0) continue;


            for(int rs = ls - 1; rs <= ls + 1; rs++){

    
                string s = "";
                string s22 = "";
                if(rs <= 0) continue;
                if(s2.size() % rs != 0) continue;
                
                vector<string> v;

                int size1, size2;
                size1 = s1.size() / ls;
                size2 = s2.size() / rs;

                for(int i = size1 - 1; i < s1.size(); i+=size1){


                    string tmp = "";

                    for(int j = i - size1 + 1; j < i - size1 + 1 + size1;j++){
                        tmp += s1[j];
                    }
                    v.pb(tmp);
                }
                int cnt = 0;
                for(int i = size2 - 1; i < s2.size(); i+=size2){


                    string tmp = "";

                    for(int j = i - size2 + 1; j < i - size2 + 1 + size2;j++){
                        tmp += s2[j];
                    }

                    s += v[cnt] + tmp;
                    s22 += tmp + v[cnt];
                    cnt++;
                }
                check.insert(s);
                check.insert(s22);

            }

            
        }
        for(auto it : check) cout << it << " ";
        // return check.find(s3) != check.end();
    }



};




int main() {
    Solution solution;
    string s1, s2, s3;cin >> s1 >> s2 >> s3;
    solution.isInterleave(s1, s2, s3);
    
    return 0;
}