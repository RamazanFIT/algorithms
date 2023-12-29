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

vector<Tree*> RRR;
void rec(Tree * tree){
    if(tree->right == NULL and tree->left == NULL){
        RRR.push_back(tree);
        return;
    }
    if(tree->right != NULL){
        rec(tree->right);
    }
    return;
}

set<int> path;
int sum = 0;

void walk(Tree * tree){
    path.insert(tree->value);
    sum += tree->value;
    cout << sum << " ";
    if(tree->left != NULL and path.find(tree->left->value) == path.end()){
        walk(tree->left);
    }
    // if(tree->prev != NULL and path.find(tree->prev->value) == path.end()){
    //     walk(tree->prev);
    // }
    if(tree->right != NULL and path.find(tree->right->value) == path.end()){
        walk(tree->right);
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
    path.insert(a);
    tree->value = a;
    for(int i = 0; i < n - 1; i++){
        int a;
        cin >> a;
        path.insert(a);
        add(tree, a, NULL);
    }
    for(auto it = path.rbegin(); it != path.rend(); it++){
        sum += *it;
        cout << sum << " ";
    }
    
    

    endd
}