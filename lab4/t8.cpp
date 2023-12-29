#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

set<int> path;

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

int maxx = 0;
Tree * start;

Tree * add(Tree * tree, int value, Tree * p){

    if(tree == NULL){
        tree = new Tree();
        tree->value = value;
        if(p != NULL)
        tree->prev = p;
        return tree;
    } else
    if(value > tree->value){
        tree->right = add(tree->right, value, tree);
    } else if(value < tree->value){
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

int ans = 0;

void rec(Tree * tree, int length){
    if(tree == NULL) return;

    ans = max(ans, length);
    if(tree->right != NULL and path.find(tree->right->value) == path.end()){
        path.insert(tree->right->value);
        rec(tree->right, length + 1);
    }
    if( tree->left != NULL and path.find(tree->left->value) == path.end()){
        path.insert(tree->left->value);

        rec(tree->left, length + 1);
    }
    if(tree->prev != NULL and path.find(tree->prev->value) == path.end()){
        path.insert(tree->prev->value);

        rec(tree->prev, length + 1);
    }
    return;
}

void to_hell(Tree * tree, int level){
    if(tree->left == NULL and tree->right == NULL){
        // nodes.insert(tree);
        if(level > maxx){
            maxx = level;
            start = tree;
        }
        return;
        
    }
    if(tree->left != NULL){
        to_hell(tree->left, level + 1);
    }
    if(tree->right != NULL){
        to_hell(tree->right, level + 1);
    }
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
        add(tree, a, NULL);
    }
    to_hell(tree, 1);
    rec(start, 1);
    cout << ans << ENDL;
    
    
    


    

    endd
}