#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

struct MyOwnList{
    string value = "";
    MyOwnList * next = NULL;
    MyOwnList * back = NULL;
};


signed main(){
    
    goodluck
    
    int n;
    cin>>n;
    MyOwnList * list = new MyOwnList;
    MyOwnList * start = list;

    for(int i = 0; i < n; i++){
        string a;
        cin>>a;
        
        list->next = new MyOwnList; 
        MyOwnList * pointter_to_back = list;
        list->value = a;
        list = list->next;
        list->back = pointter_to_back;
    }
   
    while(start->next != NULL){
        if(start->value == start->next->value){
            start->next->next->back = start->next->back;
            start->next = start->next->next;
            n--;
        } else
        start = start->next;
    }
   
    cout << "All in all: " << n << ENDL;
    cout << "Students:" << ENDL;
    start = start->back;
    while(start != NULL){
        cout << start->value << ENDL;
        start = start->back;
    }

    


    endd
}