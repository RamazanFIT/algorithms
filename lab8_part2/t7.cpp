#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


string kmp(string s, string a){
    int size = a.size();
    a = a +  "#" +  s;
    // a < s 

    vector<int> prefixfunction(a.size());
    int pointer = 0;
    int i = 1;
    int pos = 0;
    int val = 0;
    while(i < a.size()){
        if(a[pointer] == a[i]){
            prefixfunction[i] = pointer + 1;
            if(prefixfunction[i] > val){
                val = prefixfunction[i];
                pos = i;
            }
            i++;
            pointer++;
        } else if(pointer == 0){
            i++;
        } else{
            pointer = prefixfunction[pointer - 1];
        }
    }
    int cnt = 0;
    string ret = "";
    for(int i = pos - val + 1; i <= pos; i++){
        ret += a[i];
    }
    return ret;
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    if(n == 1){
        string s;
        cin >> s;
        cout << s;
        endd
    } 

    string s;
    cin >> s;
    

    for(int k = 0; k < n - 1; k++){
        string a;
        cin >> a;
        string tmp = "";
        string ans = "";
        for(int i = a.size() - 1; i >= 0; i--){
            tmp = a[i] + tmp;
            string jojo = kmp(s, tmp);
            // cout << jojo << ENDL;
            if(jojo.size() > ans.size()){
                ans = jojo;
            }
        }
        s = ans;
        
    }
    cout << s;
    // O(k * n * n)   2.5 * 1e8 operations maximum
    endd
    // exlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjqexlvqqvmfuuetjwruhzditfyftnjasowbmgsmbehrpuffkusyyptjywrmiobowxmddctzveeyyjxsgqwsjjrldxbqcgzdqwhvhdwmcbkiwmshnovtyxnmubfavnknekxjiaifmmxbqsrbzjeqydochvkwyevslzcdubkczdkaewwxmqgwqqbgqluodixkfvxrglksabkjgpjrfiqowljazuinaevyyatqmehmwbzgylhepujqsibpawmdtpfowdzkovailyjlfnumkkrcepvvrazddqzpkovohosqynonltgsvvfltdqbcwcjdokjedifytcfbvclqwqlwfbetxsyoxaivgltqrtsdvybbquppznzjsbewywpadvhhvusguxweszdjtjlafgkebgftshfzhzmepvrrsrvrzditnwaisnohgxlejalzbivlxvmdubeuwkmnzzjmekloobvapghiazzmrliqindgtunpqmqxhpoghkyjjq
}