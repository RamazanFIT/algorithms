#include <bits/stdc++.h>
#define ENDL "\n"
#define ff first 
#define ss second  
#define all(x) (x).begin(), (x).end()
#define endd return 0;
#define goodluck ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using ll = long long;
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node * parent;
    Node(){
        value = NULL;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node(int value){
        Node();
        this->value = value;
    }

    Node(int value, Node * parent){
        this->value = value;
        this->parent = parent;
    }

};


struct BinarySearchTree{
    Node * root = NULL;

    void insert(int val){
        if(root == NULL){
            root = new Node(val);
        } else{
            insert(root, val, NULL);
        }
    }
    Node * insert(Node * node, int val, Node * parent){
        if(node == NULL){
            return new Node(val, parent);
        } else{
            if(val >= node->value){
                node->right = insert(node->right, val, node);
            } else{
                node->left = insert(node->left, val, node);
            }
        }
        return node;
    }
    void show(){
        show(root);
    }
    void show(Node * tree){
        // cout << "123";
        if(tree == NULL) return;

        show(tree->left);
        show(tree->right);
        if(tree->parent != NULL)
            // cout << "Parent: " << tree->parent->value << " " << tree->left->value << " " << tree->right->value << ENDL;
            cout << "Parent: " << tree->parent->value << " " << tree->value << ENDL;

        else 
            cout << "Root: " << tree->value << ENDL; 
    }
    
};


signed main(){
    
    int x = 5;
    BinarySearchTree tree;
    tree.insert(x);
    for(int i = 10; i >= 1; i--){
        tree.insert(i);
    }
    for(int i = 1; i < 5; i++){
        tree.insert(i);
    }
    // tree.show();
}