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
    } else{
        tree->left = add(tree->left, value, tree);
    }
    return tree;
}





bool search(Tree * tree, int value){
    if(tree->value == value) return true;
    if(tree->left != NULL){
        return search(tree->left, value);
    }
    if(tree->right != NULL){
        return search(tree->right, value);
    }
    return false;
}

queue<Tree*> distance1;

void to_hell(Tree * tree){
    if(tree->left == NULL and tree->right == NULL){
        distance1.push(tree);
        return;
    }
    if(tree->left != NULL) to_hell(tree->left);
    if(tree->right != NULL) to_hell(tree->right);
}
int ans = 0;
set<int> path;
void rec(Tree * tree, int way){
    // cout << tree->value << " ";
    if(tree == NULL) return;
    if(tree->left == NULL and tree->right == NULL){
        ans = max(ans, way);
        return;
    }
    if(tree->prev != NULL and path.find(tree->prev->value) == path.end()){
        path.insert(tree->prev->value);
        rec(tree->prev, way + 1);
    }
    if(tree->left != NULL and path.find(tree->left->value) == path.end()){
        path.insert(tree->left->value);

        rec(tree->left, way + 1);
    }
    if(tree->right != NULL and path.find(tree->right->value) == path.end()){
        path.insert(tree->right->value);

        rec(tree->right, way + 1);
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
        if(!search(tree, a))
        add(tree, a, NULL);
    }
    to_hell(tree);

   
    while(!distance1.empty()){
        // rec(distance1.back(), 1);
        cout << distance1.back()->value << " ";
        distance1.pop();
        path.clear();
    }
    cout << ans << ENDL;


    

    endd
}