#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


int get_random_number(int left, int right) {
    return left + std::rand() % (right - left + 1);
}

int partition(int * a, int left, int right) {
    int pivot = get_random_number(left, right);
    // int pivot = (left + right) / 2;
    swap(a[pivot], a[right]);
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(a[j] < a[right]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[right], a[i + 1]);
    return i + 1;
}

void quick_sort(int * massive, int left, int right){
    if(left >= right) return;
    int j = partition(massive, left, right);
    quick_sort(massive, left, j);
    quick_sort(massive, j + 1, right);
    return;
}


 
 

signed main(){
    
    goodluck
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    // 6 4 2 5 7 3 1
    
    int massive[10];
    for(int i = 0; i < 10; i++){
        massive[i] = get_random_number(0, 100);
    }
 
    for(int i = 0; i < 10; i++){
        cout << massive[i] << " ";
    } cout << ENDL;
   
    quick_sort(massive, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << massive[i] << " ";
    } cout << ENDL;

    endd
}