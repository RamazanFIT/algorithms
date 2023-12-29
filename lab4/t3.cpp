#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int ans = 0;
bool flag = false;
struct Tree{

    Tree * left;
    Tree * right;
    int value;

    Tree(){
        left = NULL;
        right = NULL;
        value = -1;
    }


};
Tree * answer;

Tree * add(Tree * tree, int value){

    if(tree == NULL){
        tree = new Tree();
        tree->value = value;
        return tree;
    } else
    if(value > tree->value){
        tree->right = add(tree->right, value);
    } else{
        tree->left = add(tree->left, value);
    }
    return tree;
}

void rec(Tree * tree, int value){
    if(tree->value == value){
        answer = tree;
        return;
    }
    
    // cout << tree->value << " ";
    if(tree->right != NULL){
         rec(tree->right, value);
    } 
     if(tree->left != NULL){
         rec(tree->left, value);
    }
}

void cnt_of_subtree(Tree * tree){
    cout << tree->value << " ";
    if(tree->left != NULL){
        cnt_of_subtree(tree->left);
    }
    if(tree->right != NULL){
        cnt_of_subtree(tree->right);
    } 
    
    return;
}

signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    Tree * tree = new Tree();
    int a;
    cin >> a;
    tree->value = a;
    for(int i = 0; i < n - 1; i++){
        int a;
        cin >> a;
        add(tree, a);
    }
    int value;
    cin >> value;
    rec(tree, value);
    cnt_of_subtree(answer);
    // cout << ans << ENDL;

    


    endd
}