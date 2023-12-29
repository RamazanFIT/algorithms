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
    int value = 0;
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
        int a;
        cin>>a;
        list->next = new MyOwnList;
        MyOwnList * pointter_to_back = list;
        list->value = a;
        list = list->next;
        list->back = pointter_to_back;
    }
    
    int pos, val;
    cin>>val>>pos;
    if(pos == 0){
        list = start;
        MyOwnList * point = new MyOwnList;
        point->value = val;
        point->next = list;
        list->back = point;
        start = point;
        while(start->next != NULL){
        cout << start->value << " ";
        start = start->next;
        }
        cout << ENDL;
        return 0;
    } else if(pos == n){
        list->value = val;
        list->next = new MyOwnList;
        while(start->next != NULL){
        cout << start->value << " ";
        start = start->next;
        }
        cout << ENDL;
        return 0;
    }
    list = start;
    for(int i = 0; i < pos; i++){
        list = list->next;
    }
    MyOwnList * point = new MyOwnList;
    point->value = val;
    point->next = list;
    point->back = list->back;
    list->back->next = point;
    list->back = point;
    while(start->next != NULL){
        cout << start->value << " ";
        start = start->next;
    }
    cout << ENDL;


    

    


    endd
}