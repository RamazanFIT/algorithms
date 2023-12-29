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
    Tree * prev;
    int value;

    Tree(){
        left = NULL;
        right = NULL;
        prev = NULL;
        value = -1;
    }


};

Tree * add(Tree * tree, int value, Tree * p){

    if(tree == NULL){
        tree = new Tree();
        tree->value = value;
        if(p != NULL)
        tree->prev = p;
        return tree;
    } else
    if(value >= tree->value){
        tree->right = add(tree->right, value, tree);
    } else{
        tree->left = add(tree->left, value, tree);
    }
    return tree;
}



void show(Tree * tree){
    if(tree != NULL){
        cout << tree->value << " ";
        show(tree->right);
        show(tree->left);
    }
}

Tree * sortedArrayToBalancesTree(vector<int> & massive, int left, int right){
    if(left > right) return NULL;
    if(left < 0) return NULL;
    if(right >= massive.size()) return NULL;
    

    int middle = (right + left) / 2;
    Tree * tree = new Tree();
    tree->value = massive[middle];
    tree->left = sortedArrayToBalancesTree(massive, left, middle - 1);
    tree->right = sortedArrayToBalancesTree(massive, middle + 1, right);
    return tree;
}





signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    n = pow(2, n) - 1;
    vector<int> massive(n);

    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }
    sort(all(massive));
    Tree * tree = sortedArrayToBalancesTree(massive, 0, n - 1);
    
    show(tree);

    endd
}