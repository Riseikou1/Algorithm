#include <iostream>
using namespace std;

class Node{
public :
    int key;
    Node* left;
    Node* right;
    Node(int key) : key(key), left(nullptr), right(nullptr) {}
    Node(int key, Node* left_sub, Node* right_sub) : key(key), left(left_sub), right(right_sub) {}

};

class SplayTree{
private :
    Node* root;

    Node* zig(Node* y){  // right rotation
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        return x;
    }

    Node* zag(Node* y){   // left rotaion
        Node*x = y->right;
        y->right = x->left;
        x->left = y;
        return x;
    }

    Node* zigzig(Node* z){   // double right rotation
        return zig(zig(z));
    }
 
    Node* zagzag(Node* z){   // double left rotation.
        return zag(zag(z));
    }

    Node* zigzag(Node* z){   // left-right
        z->left = zag(z->left);
        return zig(z);
    }

    Node* zagzig(Node* z){    // right-left
        z->right = zig(z->right);  // first do right rotation on the right child and then,,
        return zag(z);             // rotate the root left.
    }

    Node* Splay(Node* t, int key){
        if(t == nullptr) return nullptr;
        if(key == t->key) return t;
        else if(key < t->key){
            if(t->left == nullptr) return t;
            if(key < t->left->key){
                t->left->left = Splay(t->left->left, key);
                return (t->left->left != nullptr) ? zigzig(t) : zig(t);
            }
            else if(key > t->left->key){
                t->left->right = Splay(t->left->right, key);
                return (t->left->right != nullptr) ? zigzag(t) : zig(t);
            }
            else zig(t);
        }
        else{
            if(t->right == nullptr) return t;
            if(key < t->right->key){
                t->right->left = Splay(t->right->left, key);
                return (t->right->left != nullptr) ? zagzig(t) : zag(t);
            }
            else if(key > t->right->key){
                t->right->right = Splay(t->right->right, key);
                return (t->right->right != nullptr) ? zagzag(t) : zag(t);
            }
            else{
                return zag(t);
            }
        }
    }

    void destroy(Node* node){
        if(!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public :
    SplayTree() : root(nullptr){}
    ~SplayTree() {destroy(root);}

    Node* Search(Node*& root, int key){
        root = Splay(root, key);
        if(key == root->key){
            return root;
        }
        else{
            return nullptr;
        }
    }

    Node* Insert(Node* root, int key){
        if(root == nullptr){
            return new Node(key);
        }
        root = Splay(root, key);
        if(key < root->key){
            root = new Node(key, root->left, root);
            root->right->left = nullptr;
        }
        else if(key > root->key){
            root = new Node(key, root, root->right);
            root->left->right = nullptr;
        }
        return root;
    }

    Node* Delete(Node* root, int key){
        root = Splay(root, key);
        if(root == nullptr || root->key != key) return root;
        Node* oldRoot = root;
        if(root->left == nullptr) root = root->right;
        else{
            Node* r = root->right;
            root = Splay(root->left, key);
            root->right = r;
        }
        delete oldRoot;
        return root;
    }
};

int main(){
    SplayTree temuujin;

    return 0;
}