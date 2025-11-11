#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left, *right;
    Node* parent;
    Node(int key, Node* parent = NULL, Node* left = NULL, Node* right = NULL) : key(key), parent(parent), left(left), right(right) {}

};

void inorder(Node *x){
    if(x != nullptr){
        inorder(x -> left);
        cout << x->key;
        inorder(x -> right);
    }
}

Node* search(Node* x, int k){
    if(x == NULL) return NULL;
    if(k == x->key){
        return x;
    }
    else if(k < x->key){
        return search(x->left, k);
    }
    else{
        return search(x->right, k);
    }
}

Node* searchIterative(Node* x, int k){
    while(x != NULL && k != x->key){
        if(k < x->key) x = x->left;
        else           x = x->right;
    }
    return x;
}

Node* Maximum(Node* x){
    if(x->right == NULL){
        return x;
    }
    return Maximum(x->right);
}

Node* MaximumIterative(Node* x){
    if(x == NULL) return nullptr;
    while(x->right != NULL){
        x = x->right;
    }
    return x;
}

Node* Minimum(Node* x){
    if(x->left == NULL){
        return x;
    }
    return Minimum(x->left);
}

Node* MinimumIterative(Node* x){
    if(x == nullptr) return nullptr;
    while(x -> left != nullptr){
        x = x->left ;
    }
    return x;
}

Node* Successor(Node* x){
    if(x->right != NULL){
        return Minimum(x->right);
    }
    Node* parent = x->parent;
    while(parent != nullptr && x == parent->right){
        x = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* predecessor(Node* x){
    if (x->left != nullptr){
        return Maximum(x->left);
    }
    Node*parent = x->parent;
    while(parent != nullptr && x == parent->left){
        x = parent;
        parent = parent->parent;
    }
    return parent;
}

void Insert(Node*& t, int k){
    Node* current= t;
    Node* parent= nullptr;
    while(current != nullptr){
        parent = current;
        if(k < current->key){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    Node* newNode = new Node(k, parent);
    if(parent == nullptr){
        t = newNode;
    }
    else if(k < parent->key){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
}

void disConnect(Node* root, Node* curr, Node* child){
    Node* parent = curr->parent;
    if(parent == nullptr) root = child;
    else if(curr == parent->left) parent->left = child;
    else parent->right = child;
    if(child != nullptr) child->parent = parent;
}

void Delete(Node*& root, Node* t){
    if(t->left == nullptr) disConnect(root, t, t->right);
    else if(t->right== nullptr) disConnect(root, t, t->left);
    else {
        Node* succ = Minimum(t->right);
        if(succ != t->right){
            disConnect(root, succ, succ->right);
            succ->right = t->right;
            succ->right->parent = succ;
        }
        disConnect(root, t, succ);
        succ->left = t->left;
        succ->left->parent = succ;
    }
    delete t;
}

int main(){

    return 0;
}