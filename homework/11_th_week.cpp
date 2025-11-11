#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, cnt, sz;    
    Node* left, *right;

    Node(int key, Node* left = nullptr, Node* right = nullptr) : key(key), cnt(1), sz(1), left(left), right(right) {}
};

int GetSize(Node* x) {
    return x ? x->sz : 0;
}

void Resize(Node* x) {
    if (!x) return;
    x->sz = x->cnt + GetSize(x->left) + GetSize(x->right);
}

void DestroySplayTree(Node* root) {
    if (!root) return;
    DestroySplayTree(root->left);
    DestroySplayTree(root->right);
    delete root;
}

Node* Zig(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    Resize(y);
    Resize(x);
    return x;
}

Node* Zag(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    Resize(x);
    Resize(y);
    return y;
}

Node* Splay(Node* t, int key) {
    if (!t) return nullptr;

    if (key < t->key) {
        if (!t->left) return t;

        if (key < t->left->key) {
            t->left->left = Splay(t->left->left, key);
            t = Zig(t);
        } 
        else if (key > t->left->key) {
            t->left->right = Splay(t->left->right, key);
            if (t->left->right) t->left = Zag(t->left);
        }

        return (t->left ? Zig(t) : t);
    } 
    else if (key > t->key) {
        if (!t->right) return t;

        if (key > t->right->key) {
            t->right->right = Splay(t->right->right, key);
            t = Zag(t);
        } 
        else if (key < t->right->key) {
            t->right->left = Splay(t->right->left, key);
            if (t->right->left) t->right = Zig(t->right);
        }

        return (t->right ? Zag(t) : t);
    } 

    return t;
}


Node* Insert(Node* root, int key) {
    if (!root) return new Node(key);
    root = Splay(root, key);

    if (key == root->key) {
        root->cnt++;
        Resize(root);
        return root;
    }

    Node* n = new Node(key);
    if (key < root->key) {
        n->right = root;
        n->left = root->left;
        root->left = nullptr;
    } else {
        n->left = root;
        n->right = root->right;
        root->right = nullptr;
    }
    Resize(root);
    Resize(n);
    return n;
}

Node* Delete(Node* root, int key) {
    if (!root) return nullptr;
    root = Splay(root, key);
    if (root->key != key) return root;

    if (root->cnt > 1) {
        root->cnt--;
        Resize(root);
        return root;
    }

    Node* res;
    if (!root->left) {
        res = root->right;
    } else {
        res = Splay(root->left, key);
        res->right = root->right;
    }
    delete root;
    Resize(res);
    return res;
}

int Order(Node* t, int k) {
    if (!t || k <= 0 || k > GetSize(t)) return -1;

    int leftSize = GetSize(t->left);
    if (k <= leftSize) return Order(t->left, k);
    if (k <= leftSize + t->cnt) return t->key;
    return Order(t->right, k - leftSize - t->cnt);
}

int OrderOfKey(Node* t, int x) {
    if (!t) return 0;
    if (x <= t->key) return OrderOfKey(t->left, x);
    else             return GetSize(t->left) + t->cnt + OrderOfKey(t->right, x);
}

int main() {
    int temu; cin >> temu;
    while (temu--) {
        int q; cin >> q;
        Node* root = nullptr;
        for (int i = 0; i < q; i++) {
            int op, x; cin >> op >> x;
            if (op == 1) root = Insert(root, x);
            else if (op == 2) root = Delete(root, x);
            else if (op == 3) cout << Order(root, x) << "\n";
            else if (op == 4) cout << OrderOfKey(root, x) << "\n";
        }
        DestroySplayTree(root);
    }
    return 0;
}
