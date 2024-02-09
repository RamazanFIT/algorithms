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

void insert_at_position(Tree * tree, int a, int b, int z){
    if(tree == NULL) return;
    if(tree->value == a){
        if(z){
            tree->right = new Tree();
            tree->right->value = b;
            return;
        } else{
            tree->left = new Tree();
            tree->left->value = b;
            return;
        }
    }
    insert_at_position(tree->left, a, b, z);
    insert_at_position(tree->right, a, b, z);
}

int ans = 0;

void width(Tree * tree, int level, int current_level){
    if(level == current_level){
        ans++;
        return;
    }
    if(tree->left != NULL){
        width(tree->left, level, current_level + 1);
    }
    if(tree->right != NULL){
        width(tree->right, level, current_level + 1);
    }
}

int max_level = 0;
void get_level(Tree * tree, int level){
    max_level = max(max_level, level);
    if(tree->left != NULL){
        get_level(tree->left, level + 1);
    }
    if(tree->right != NULL){
        get_level(tree->right, level + 1);
    }
}
signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin>>n;
    Tree * tree = new Tree();
    tree->value = 1;
    for(int i = 0; i < n - 1; i++){
        int a, b, z;
        cin >> a >> b >> z;
        insert_at_position(tree, a, b, z);
    }
    int real_ans = 0;
    get_level(tree, 0);
    for(int i = 0; i <= max_level; i++){
        width(tree, i, 0);
        real_ans = max(real_ans, ans);
        ans = 0;
    }
    cout << real_ans << ENDL;
    

    endd
}