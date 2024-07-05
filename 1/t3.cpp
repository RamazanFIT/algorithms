/* 
    Bismillah 
 Ù„Ø§ Ø¥Ù„Ù‡ Ø¥Ù„Ø§ Ø§Ù„Ù„Ù‡ Ù…Ø­Ù…Ø¯ Ø±Ø³ÙˆÙ„ Ø§Ù„Ù„Ù‡
 Al'-Phatixa
 Ø¨ÙØ³Ù’Ù…Ù Ù±Ù„Ù„ÙŽÙ‘Ù‡Ù Ù±Ù„Ø±ÙŽÙ‘Ø­Ù’Ù…ÙŽÙ°Ù†Ù Ù±Ù„Ø±ÙŽÙ‘Ø­ÙÙŠÙ…Ù
 Ù±Ù„Ù’Ø­ÙŽÙ…Ù’Ø¯Ù Ù„ÙÙ„ÙŽÙ‘Ù‡Ù Ø±ÙŽØ¨ÙÙ‘ Ù±Ù„Ù’Ø¹ÙŽÙ°Ù„ÙŽÙ…ÙÙŠÙ†ÙŽ
 Ù±Ù„Ø±ÙŽÙ‘Ø­Ù’Ù…ÙŽÙ°Ù†Ù Ù±Ù„Ø±ÙŽÙ‘Ø­ÙÙŠÙ…Ù
 Ù…ÙŽÙ°Ù„ÙÙƒÙ ÙŠÙŽÙˆÙ’Ù…Ù Ù±Ù„Ø¯ÙÙ‘ÙŠÙ†Ù
 Ø¥ÙÙŠÙŽÙ‘Ø§ÙƒÙŽ Ù†ÙŽØ¹Ù’Ø¨ÙØ¯Ù ÙˆÙŽØ¥ÙÙŠÙŽÙ‘Ø§ÙƒÙŽ Ù†ÙŽØ³Ù’ØªÙŽØ¹ÙÙŠÙ†Ù
 Ù±Ù‡Ù’Ø¯ÙÙ†ÙŽØ§ Ù±Ù„ØµÙÙ‘Ø±ÙŽÙ°Ø·ÙŽ Ù±Ù„Ù’Ù…ÙØ³Ù’ØªÙŽÙ‚ÙÙŠÙ…ÙŽ
 ØµÙØ±ÙŽÙ°Ø·ÙŽ Ù±Ù„ÙŽÙ‘Ø°ÙÙŠÙ†ÙŽ Ø£ÙŽÙ†Ù’Ø¹ÙŽÙ…Ù’ØªÙŽ Ø¹ÙŽÙ„ÙŽÙŠÙ’Ù‡ÙÙ…Ù’ ØºÙŽÙŠÙ’Ø±Ù Ù±Ù„Ù’Ù…ÙŽØºÙ’Ø¶ÙÙˆØ¨Ù Ø¹ÙŽÙ„ÙŽÙŠÙ’Ù‡ÙÙ…Ù’ ÙˆÙŽÙ„ÙŽØ§ Ù±Ù„Ø¶ÙŽÙ‘Ø¢Ù„ÙÙ‘ÙŠÙ†ÙŽ
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

using ll = uint32_t;
using namespace std;

void solve(int ccase){
    int S1, S2;get(S1, S2);
    int answer = S1 + S2;
        int a1, a2, b1, b2;
    a1 = a2 = b1 = b2 = 1;
	vii a, b;
	
    for(int i = 1; i < sqrt(S1 + 1) + 1; i++){
        if(S1 % i == 0ll){
//            b1 = S1 / i;
//            a1 = i;
           	
			a.pb(i);
            
//            for(int  j < sqrt(S2 + 1) + 1; j++){
//                if(S2 % j == 0){
//                    b2 = S2 / j;
//                    a2 = j;
//                    answer = min(answer, max(a1 + a2, max(b1, b2)));
//                    answer = min(answer, max(b1 + b2, max(a1, a2)));
//                    answer = min(answer, max(b1 + b2, a1 + a2));
//                }
//            }
        }
    }
    for(int j = 1; j < sqrt(S2 + 1) + 1; j++){
                if(S2 % j == 0ll){
                	b.pb(j);
//                    b2 = S2 / j;
//                    a2 = j;
//                    answer = min(answer, max(a1 + a2, max(b1, b2)));
//                    answer = min(answer, max(b1 + b2, max(a1, a2)));
//                    answer = min(answer, max(b1 + b2, a1 + a2));
                }
            }
    for(auto it1 : a){
        a1 = it1;
        b1 = S1 / a1;
    	for(auto it2 : b){
    		
    		a2 = it2;
    		b2 = S2 / it2;
            answer = min(answer, max(a1 + a2, max(b1, b2)));
            // answer = min(answer, max(b1 + b2, max(a1, a2)));
            // answer = min(answer, max(b1 + b2, a1 + a2));
		}
	}
    put(answer);
    
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