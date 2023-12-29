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
    
    void * insert(int x){
        if(root == NULL){
            root = new Node(x, NULL);
        } else{
            insert(root, x, root);
        }
    }

    Node * insert(Node * root, int x, Node * parent){
        if(root == NULL){
            return new Node(x, parent);
        }
        if(x >= root->value){
            root->right = insert(root->right, x, root);
        } else{
            root->left = insert(root->left, x, root);
        }
        return root;
    }

    void show(){
        show(root);
    }

    void show(Node * tree){
        if(tree == NULL) return;
        show(tree->left);
        show(tree->right);
        if(tree->parent != NULL)
        cout << "Parent: " << tree->parent->value << " " << tree->value << " ,";

        else cout  << " " << tree->value << " ,";
        // cout << ENDL;
    }

    void erase (int x){
        Node * subtree = find(root, x);
        // cout << subtree->value << " subtree " <<  ENDL;
        if(subtree == NULL) return;
        if(subtree->left == NULL and subtree->right == NULL){
            if(subtree->parent->value > subtree->value){
                subtree->parent->left = NULL;
            } else{
                subtree->parent->right = NULL;
            }
            return;
        }
        if(subtree->left == NULL){
            if(subtree->parent->value > subtree->value){
                subtree->parent->left = subtree->right;
                subtree->right->parent = subtree->parent;
            } else{
                subtree->parent->right = subtree->right;
                subtree->right->parent = subtree->parent;
            }
            return;
        }
        if(subtree->right == NULL){
            if(subtree->parent->value > subtree->value){
                subtree->parent->left = subtree->left;
                subtree->left->parent = subtree->parent;
            } else{
                subtree->parent->right = subtree->left;
                subtree->left->parent = subtree->parent;
            }
            return;
        }
        Node * left = getLeftMost(subtree->right);
        // cout << subtree->value << " subtree " << left->value << ENDL;
        if(left->right != NULL){
            left->right->parent = left->parent;
            left->parent->left = left->right;
            subtree->value = left->value;//error maybe
        } else{
            subtree->value = left->value;
            left->parent->left = NULL;
        }
    }

    Node * find(Node * root, int x){
        // if(root != NULL){
        if(root == NULL) return NULL;
        if(root->value == x){
            return root;
        }
        else{
            if(x >= root->value){
                return find(root->right, x);
            } else return find(root->left, x);
        }
        // }
        // return NULL;
    }

    Node * getLeftMost(Node * tree){
       
        if(tree->left != NULL){
            return getLeftMost(tree->left);
        } else{
            return tree;
        }
    }
    
};


signed main(){
    
    goodluck
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    BinarySearchTree tree;
    tree.insert(5);
    for(int i = 10; i >= 1; i--){
        tree.insert(i);
    }
    // tree.show();
    // tree.erase(2);
    // tree.erase(5);
    // tree.erase(4);
    // tree.erase(10);
    // tree.show();
    // for(int i = 1; i <= 4; i++){
    //     // tree.show();
    //     tree.erase(i);
    // }
    for(int i = 4; i <= 10; i++){
        // tree.show();
        tree.erase(i);
    }
    tree.erase(1);
    tree.show();
    endd
}