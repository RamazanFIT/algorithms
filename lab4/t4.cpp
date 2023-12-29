#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

int size_of_tree = 0;
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

void cnt_of_subtree(Tree * tree, int level, vector<int> & massive){
    massive[level] += tree->value;
    size_of_tree = max(size_of_tree, level);
    if(tree->right != NULL){
        cnt_of_subtree(tree->right, level + 1, massive);
    } 
    if(tree->left != NULL){
        cnt_of_subtree(tree->left, level + 1, massive);
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
    vector<int> massive(5000, 0);
    cnt_of_subtree(tree, 0, massive);
    cout << size_of_tree + 1<< ENDL;
    for(int i = 0; i <= size_of_tree; i++) cout << massive[i] << " ";


    endd
}