#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;




void sortedArrayToBalancesTree(vector<int> & massive, int left, int right){
    if(left > right) return;
    if(left < 0) return;
    if(right >= massive.size()) return;
    

    int middle = (right + left) / 2;

    cout <<  massive[middle] << " "; 
    sortedArrayToBalancesTree(massive, left, middle - 1);
    sortedArrayToBalancesTree(massive, middle + 1, right);
    return;
}





signed main(){
    
    goodluck

    int n;
    cin>>n;
    n = pow(2, n) - 1;
    vector<int> massive(n);

    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    sort(all(massive));
    sortedArrayToBalancesTree(massive, 0, n - 1);
    


    endd
}