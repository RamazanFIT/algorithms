#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;


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


int ans = 0;


void rec(Tree * tree){
    if(tree == NULL) return;
    if(tree->left != NULL and tree->right != NULL) ans++;
    if(tree->left != NULL) rec(tree->left);
    if(tree->right != NULL) rec(tree->right);
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
    rec(tree);
    cout << ans << ENDL;

    endd
}