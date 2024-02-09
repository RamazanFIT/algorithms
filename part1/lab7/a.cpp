#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


//Разделяй и влавствуй как Папа Карло !!!
void merge_sort(vector<string> & massive, int left, int right){
    if(left >= right){
        return;
    }
    // stop 
    int middle = (right + left) / 2;
    merge_sort(massive, left, middle);
    merge_sort(massive, middle + 1, right);
    int index = left;
    int index2 = middle + 1;
    vector<string> tmp;
    while(true){
        if((index >= middle + 1) or (index2 >= right + 1)){
            break;
        }

        if(massive[index].size() > massive[index2].size()){
            tmp.push_back(massive[index2]);
            index2++;
        } else{
            tmp.push_back(massive[index]);
            index++;
        }
       
    }
    for(int i = index; i <= middle; i++){
        tmp.push_back(massive[i]);
    }
    for(int i = index2; i <= right; i++){
        tmp.push_back(massive[i]);
    }
    int some_index = 0;
    for(int i = left; i <= right; i++){
        massive[i] = tmp[some_index];
        some_index++;
    }  
}


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int n;
    cin >> n;
    bool flag = true;
    while(n--){
        string s;
        char some_char_to_add;
        cin >> some_char_to_add;
        int k = 0;
        std::getline(std::cin, s);
        
        vector<string> massive;
        string tmp = "";
        s += " *";
        s = some_char_to_add + s;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                massive.push_back(tmp);
                tmp = "";
                k++;
            } else{
                tmp += s[i];
            }
        }
        merge_sort(massive, 0, k - 1);

        for(int i = 0; i < k; i++){
            cout << massive[i] << " ";
        } cout << ENDL;
    }

    
    endd
}