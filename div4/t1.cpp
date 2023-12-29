#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n, k;
    cin>>n>>k;
    vector<int> massive(n);
    int w[k];
    int sum = 0;
    int tmp = n / k;
    int index = 0;
    int max_ = INT_MIN;
    vector<int> indexes(k - 1);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
        sum += massive[i];
        max_ = max(max_, sum);
        if((i + 1) % tmp == 0){
            w[index] = sum;
            sum = 0;
            indexes[index] = i;
            index++;
        }
    }
    w[index] = sum;
    for(int i = 0; i < indexes.size(); i++){
        int a = w[i];
        int b = w[i + 1];
        if(indexes.size() >= 2)
        for(int j = indexes[i] + 1; j <= indexes[i + 1]; j++){
            w[i] += massive[j];
            w[i + 1] -= massive[j];
            int tmp_max = max(w[i], w[i + 1]);
            max_ = min(max_, tmp_max);
        }
        
        w[i] = a;
        w[i + 1] = b;
        for(int j = indexes[0]; j >= 0; j--){
            w[i] -= massive[j];
            w[j] += massive[j];
            int tmp_max = max(w[i], w[i + 1]);
            max_ = min(max_, tmp_max);
        }
        w[i] = a;
        w[i + 1] = b;
        if(indexes.size() >= 2)
        for(int j = indexes[i + 1]; j > indexes[i]; j--){
            w[i] -= massive[j];
            w[j] += massive[j];
            int tmp_max = max(w[i], w[i + 1]);
            max_ = min(max_, tmp_max);
        }
        w[i] = a;
        w[i + 1] = b;
    }
    cout << max_ << ENDL;
   
    


    endd
}