#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int cnt; // count of duplicates
    int sz;  // size of subtree
    Node* left;
    Node* right;

    Node(int key, Node* left = nullptr, Node* right = nullptr)
        : key(key), cnt(1), sz(1), left(left), right(right) {}
};

class SplayTree {
private:
    Node* root = nullptr;

    void DestroySplayTree(Node* t) {
        if (!t) return;
        DestroySplayTree(t->left);
        DestroySplayTree(t->right);
        delete t;
    }

    int getSize(Node* x) {
        return x ? x->sz : 0;
    }

    void reSize(Node* x) {
        if (!x) return;
        x->sz = x->cnt + getSize(x->left) + getSize(x->right);
    }

    Node* zig(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        reSize(y);
        reSize(x);
        return x;
    }

    Node* zag(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        reSize(x);
        reSize(y);
        return y;
    }

    Node* Splay(Node* t, int key) {
        if (t == nullptr) return nullptr;
        if (key == t->key) return t;

        if (key < t->key) {
            if (t->left == nullptr) return t;
            if (key < t->left->key) {
                t->left->left = Splay(t->left->left, key);
                t = zig(t);
            } else if (key > t->left->key) {
                t->left->right = Splay(t->left->right, key);
                if (t->left->right != nullptr) t = zig(t);
            }
            return t->left ? zig(t) : t;
        } else {
            if (t->right == nullptr) return t;
            if (key > t->right->key) {
                t->right->right = Splay(t->right->right, key);
                t = zag(t);
            } else if (key < t->right->key) {
                t->right->left = Splay(t->right->left, key);
                if (t->right->left != nullptr) t = zag(t);
            }
            return t->right ? zag(t) : t;
        }
    }

    Node* insert(Node* t, int key) {
        if (t == nullptr) return new Node(key);
        t = Splay(t, key);

        if (key == t->key) {
            t->cnt++;
            reSize(t);
            return t;
        }

        Node* n = new Node(key);
        if (key < t->key) {
            n->right = t;
            n->left = t->left;
            t->left = nullptr;
        } else {
            n->left = t;
            n->right = t->right;
            t->right = nullptr;
        }
        reSize(t);
        reSize(n);
        return n;
    }

    Node* remove(Node* t, int key) {
        if (t == nullptr) return nullptr;
        t = Splay(t, key);

        if (t->key != key) return t;

        if (t->cnt > 1) {
            t->cnt--;
            reSize(t);
            return t;
        }

        Node* result;
        if (t->left == nullptr) {
            result = t->right;
        } else {
            result = Splay(t->left, key);
            result->right = t->right;
        }
        delete t;
        reSize(result);
        return result;
    }

    int countOfKey(Node* t, int key) {
        if (!t) return 0;
        t = Splay(t, key);
        root = t;
        return (t->key == key) ? t->cnt : 0;
    }

    int kth(Node* t, int k) {
        if (!t || k <= 0 || k > getSize(t)) return -1;
        int leftSize = getSize(t->left);
        if (k <= leftSize) return kth(t->left, k);
        if (k <= leftSize + t->cnt) return t->key;
        return kth(t->right, k - leftSize - t->cnt);
    }

public:
    SplayTree() = default;
    ~SplayTree() { DestroySplayTree(root); }

    void Insert(int key) { root = insert(root, key); }
    void Remove(int key) { root = remove(root, key); }
    int Count(int key) { return countOfKey(root, key); }
    int Kth(int k) { return kth(root, k); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    cin >> w;
    while (w--) {
        int queries;
        cin >> queries;
        SplayTree tree;

        for (int i = 0; i < queries; i++) {
            int query, x;
            cin >> query >> x;
            if (query == 1) {
                tree.Insert(x);
            } else if (query == 2) {
                tree.Remove(x);
            } else if (query == 3) {
                cout << tree.Kth(x) << "\n";
            } else if (query == 4) {
                cout << tree.Count(x) << "\n";
            }
        }
    }
    return 0;
}
