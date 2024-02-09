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



Tree * insert(Tree * tree, int value){
    if(tree == NULL){
        tree = new Tree();
        tree->value = value;
        return tree;
    } else if(value < tree->value){
        tree->left = insert(tree->left, value);
    } else{
        tree->right = insert(tree->right, value);
    }
    return tree;
}

bool check(Tree * tree, string s, int index){
    // cout << tree->value << " ";
    if(index < s.size() and s[index] == 'R'){
        if(tree->right != NULL){
            return check(tree->right, s, index + 1);
        } else{
            return false;
        }
    } else if(index < s.size() and s[index] == 'L'){
        if(tree->left != NULL){
            return check(tree->left, s, index + 1);
        } else{
            return false;
        }
    }
    return true;
 
}

// void show(Tree * tree){
//     if(tree != NULL){
//         cout << tree->value << " ";
//         show(tree->right);
//         show(tree->left);
//     }
// }


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    int n;
    cin >> n;
    int k;
    cin >> k;

    Tree * tree = new Tree();
    int a;
    cin >> a;
    tree->value = a;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        insert(tree, a);
    }
    for(int i = 0; i < k; i++){
        string a;
        cin >> a;
        
        if(check(tree, a, 0)) cout << "YES" << ENDL;
        else cout << "NO" << ENDL;
       
        // cout << ENDL;
    }
    // show(tree);
    


    endd
}