#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;


struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
    int color; // 1 red, 0 black
};

typedef Node* NodePtr;

class RBTree {
private:
    NodePtr root;
    NodePtr TNULL;
    
    NodePtr searchTreeHelper(NodePtr node, int key) {
        if (node == TNULL || key == node->data) {
            return node;
        }
        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void Insert_Balance(NodePtr k) {
        NodePtr u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left; // uncle
                if (u->color == 1) { // u red
                    // 1 right
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        // 2.2 right
                        k = k->parent;
                        rightRotate(k);  // left case of right
                    }
                    // 2.1 right
                    k->parent->color = 0; // u black
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            }
            else { // mirror case all is just inverted
                u = k->parent->parent->right; // uncle

                if (u->color == 1) {
                    // 1 left
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        // 2.2 left
                        k = k->parent;
                        leftRotate(k);
                    }
                    // 2.1 left
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) { // balance of root is default
                break;
            }
        }
        root->color = 0; // unbreakable law
    }

    void Delete_Balance(NodePtr x) {
        NodePtr s;
        while (x != root+1 && x->color == 0) { // 2 -> 1 -> 3 -> 4
            if (x == x->parent->left) {  // left case
                s = x->parent->right;
                if (s->color == 1) { // sibling red
                    // 1 left
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                if (s->left->color == 0 && s->right->color == 0) { // both s childs black
                    // 2 left
                    s->color = 1;
                    x = x->parent; // ascend and back to 1,3 left
                }
                else {
                    if (s->right->color == 0) {    // s left child red , right black
                        // 3 left
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    // 4 left
                    s->color = x->parent->color; // s right child red,  cycle quit
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root+1;
                }
            }
            else { // all is reverted (r -> l, l -> r)
                s = x->parent->left;
                if (s->color == 1) {
                    // 1 right
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0) {
                    // 2 right
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    if (s->left->color == 0) {
                        // 3 right
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    // 4 right
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }


    void move(NodePtr u, NodePtr v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteAllHelper(NodePtr node) {
        if (node->left != nullptr && node->left != TNULL)
            deleteAllHelper(node->left);
        if (node->right != nullptr && node->right != TNULL)
            deleteAllHelper(node->right);
        node->left = nullptr;
        node->right = nullptr;
        if(node != root)
            delete node;
    }

    void deleteNodeHelper(NodePtr node, int key) {
        NodePtr z = TNULL;
        NodePtr x, y;
        while (node != TNULL) {
            if (node->data == key) {
                z = node;
            }

            if (node->data <= key) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        if (z == TNULL) {
            cout << "Wrong key " << endl;
            return;
        }
        count--;

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            move(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            move(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                move(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            move(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            Delete_Balance(x);
        }
    }





public:
    int count = 0;
    RBTree() {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
        count = 0;
    }

    NodePtr searchTree(int k) {
        return searchTreeHelper(this->root, k); //link
    }

    NodePtr minimum(NodePtr node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    NodePtr maximum(NodePtr node) {
        while (node->right != TNULL) {
            node = node->right;
        }
        return node;
    }



    void insert(int key) {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1; // new node red
        count++;

        NodePtr y = nullptr;
        NodePtr x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            }
            else if (node->data == x->data) {
                count--;
                return;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        }
        else if (node->data < y->data) {
            y->left = node;
        }
        else {
            y->right = node;
        }

        // new node is a root node
        if (node->parent == nullptr) {
            node->color = 0;
            return;
        }

        // grandpa is null
        if (node->parent->parent == nullptr) {
            return;
        }

        // balance tree
        Insert_Balance(node);
    }

    NodePtr getRoot() {
        return this->root;
    }

    void deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }

    void deleteAll() {
        deleteAllHelper(this->root);
        count = 0;
        root = TNULL;
    }
    void prettyPrint() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }
    void printHelper(NodePtr root, string indent, bool last) {
        // print the tree structure on the screen
        if (root != TNULL) {
            cout<<indent;
            if (last) {
                cout<<"R----";
                indent += "     ";
            } else {
                cout<<"L----";
                indent += "|    ";
            }

            string sColor = root->color?"RED":"BLACK";
            cout<<root->data<<"("<<sColor<<")"<<endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
        // cout<<root->left->data<<endl;
    }
};


int main() {
    RBTree a;
    int N = 10;
    for (int i  = 0; i < N; ++i){
        a.insert(i);
    }
    a.prettyPrint();
    a.deleteNode(1);
    a.prettyPrint();

    return 0;
};

