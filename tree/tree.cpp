#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;
    friend class Tree;

public:
    explicit Node(int data)
        : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;
    int n;

    void clear(Node* node);
    Node* insert(Node* node, int x);
    bool search(Node* node, int x);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    void print(Node* node, int depth);

public:
    Tree();
    ~Tree();

    int size();
    bool empty();

    void insert(int x);
    void search(int x);
    void inorder();
    void preorder();
    void postorder();
    void print();
};

Tree::Tree()
    : root(nullptr), n(0) {}

Tree::~Tree() {
    clear(root);
}

void Tree::clear(Node* node) {
    if (node == nullptr) return;

    clear(node->left);
    clear(node->right);
    delete node;
}

int Tree::size() {
    return n;
}

bool Tree::empty() {
    return n == 0;
}

Node* Tree::insert(Node* node, int x) {
    if (node == nullptr) {
        cout << "Inserted: " << x << endl;
        n++;
        return new Node(x);
    }

    cout << "Compare with " << node->data << " -> ";

    if (x < node->data) {
        cout << "go left\n";
        node->left = insert(node->left, x);
    }
    else if (x > node->data) {
        cout << "go right\n";
        node->right = insert(node->right, x);
    }
    else {
        cout << "duplicate value, ignored\n";
    }

    return node;
}

void Tree::insert(int x) {
    cout << "\nInsert: " << x << endl;

    print();
    this_thread::sleep_for(chrono::milliseconds(250));

    root = insert(root, x);

    this_thread::sleep_for(chrono::milliseconds(300));

    cout << "\nResult:\n";
    print();
}

bool Tree::search(Node* node, int x) {
    if (node == nullptr) {
        cout << "NULL -> not found\n";
        return false;
    }

    cout << node->data;

    if (x == node->data) {
        cout << " -> found\n";
        return true;
    }
    else if (x < node->data) {
        cout << " -> left\n";
        return search(node->left, x);
    }
    else {
        cout << " -> right\n";
        return search(node->right, x);
    }
}

void Tree::search(int x) {
    cout << "\nSearch: " << x << endl;

    if (empty()) {
        cout << "Root: NULL\n";
        return;
    }

    bool result = search(root, x);

    if (result) cout << "Result: Found\n";
    else cout << "Result: Not Found\n";
}

void Tree::inorder(Node* node) {
    if (node == nullptr) return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void Tree::preorder(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void Tree::postorder(Node* node) {
    if (node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void Tree::inorder() {
    cout << "\nInorder: ";
    if (empty()) cout << "NULL";
    else inorder(root);
    cout << "\n";
}

void Tree::preorder() {
    cout << "\nPreorder: ";
    if (empty()) cout << "NULL";
    else preorder(root);
    cout << "\n";
}

void Tree::postorder() {
    cout << "\nPostorder: ";
    if (empty()) cout << "NULL";
    else postorder(root);
    cout << "\n";
}

void Tree::print(Node* node, int depth) {
    if (node == nullptr) return;

    print(node->right, depth + 1);

    for (int i = 0; i < depth; i++) {
        cout << "    ";
    }
    cout << node->data << "\n";

    print(node->left, depth + 1);
}

void Tree::print() {
    cout << "\nRoot\n ↓\n";

    if (empty()) {
        cout << "NULL\n";
        return;
    }

    print(root, 0);
}

void treeMenu() {
    Tree tree;
    int choice, x;

    while (true) {
        cout << "\n--- Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Inorder\n";
        cout << "4. Preorder\n";
        cout << "5. Postorder\n";
        cout << "6. Size\n";
        cout << "7. Empty\n";
        cout << "8. Print\n";
        cout << "0. Back\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> x;
            tree.insert(x);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> x;
            tree.search(x);
        }
        else if (choice == 3) {
            tree.inorder();
        }
        else if (choice == 4) {
            tree.preorder();
        }
        else if (choice == 5) {
            tree.postorder();
        }
        else if (choice == 6) {
            cout << "Size: " << tree.size() << endl;
        }
        else if (choice == 7) {
            cout << (tree.empty() ? "Empty\n" : "Not Empty\n");
        }
        else if (choice == 8) {
            tree.print();
        }
        else if (choice == 0) {
            break;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n==== Data Structure Visualizer ====\n";
        cout << "1. Tree\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) treeMenu();
        else if (choice == 0) break;
    }

    return 0;
}
