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
void merge_sort(vector<int> & massive, int left, int right){
    if(left >= right){
        return;
    }
    // stop 
    int middle = (right + left) / 2;
    merge_sort(massive, left, middle);
    merge_sort(massive, middle + 1, right);
    int index = left;
    int index2 = middle + 1;
    vector<int> tmp;
    while(true){
        if((index >= middle + 1) or (index2 >= right + 1)){
            break;
        }

        if(massive[index] > massive[index2]){
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

    vector<int> massive;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        massive.push_back(a);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        massive.push_back(a);
    }
    
    merge_sort(massive, 0, n + m - 1);
    for(int i = 0; i < n + m; i++){
        cout << massive[i] << " ";
    }

    
    endd
}