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

    Node * left;
    Node * right;
    int value;

    Node(){
        left = nullptr;
        right = nullptr;
        value = 0;
    }
    Node(int value){
        left = nullptr;
        right = nullptr;
        this->value = value;
    }

};

Node* insert(Node * tree, int value){
    if(tree == nullptr){
        return new Node(value);
    }
    if(value >= tree->value){
        tree->right = insert(tree->right, value);
    } else{
        tree->left = insert(tree->left, value);
    }
    return tree;
}

void show(Node* tree){
    if(tree == nullptr) return;
    cout << tree->value << ": ";
    if(tree->left != nullptr) cout << "left: " << tree->left->value;
    if(tree->right != nullptr) cout << " right: " << tree->right->value << ENDL;
    else cout << ENDL;
    show(tree->left);
    show(tree->right);
}

    //       500
    // 12            234234
    //     344    23324
    // 24       2424


//             500
//      24             23324
// 12      344    2424      234234

Node * sortedArrayToBalancedTree(vector<int> massive, int left, int right){
    if(left < 0) return nullptr;
    if(right >= massive.size()) return nullptr;
    if(left > right) return nullptr;
    int mid = (right + left) / 2;
    Node * tree = new Node(massive[mid]);
    tree->left = sortedArrayToBalancedTree(massive, left, mid - 1);
    tree->right = sortedArrayToBalancedTree(massive, mid + 1, right);
    return tree;
}

signed main(){
    
    goodluck
    freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);

    
    int n;
    cin >> n;
    vector<int> massive(n);
    for(int i = 0; i < n; i++){
        cin >> massive[i];
    }

    sort(all(massive));

    Node * tree = sortedArrayToBalancedTree(massive, 0, n - 1);
    // int x;
    // cin >> x;
    // tree->value = x;
    // for(int i = 0; i < n - 1; i++){
    //     int a;
    //     cin >> a;
    //     insert(tree, a);
    // }
    
    show(tree);
    


    endd
}