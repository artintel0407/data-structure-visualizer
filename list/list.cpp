#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    friend class LinkedList;
public:
    explicit Node(int data)
        : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int n;

public:
    LinkedList();
    ~LinkedList();

    int size();
    bool empty();
    int front();
    int back();

    void insertFront(int x);
    void insertBack(int x);
    void removeFront();
    void removeBack();
    void print();
};

LinkedList::LinkedList()
    : head(nullptr), n(0) {}

LinkedList::~LinkedList() {
    while (!empty()) removeFront();
}

int LinkedList::size() { return n; }
bool LinkedList::empty() { return n == 0; }

int LinkedList::front() {
    if (empty()) return -1;
    return head->data;
}

int LinkedList::back() {
    if (empty()) return -1;

    Node* cur = head;
    while (cur->next != nullptr)
        cur = cur->next;
    return cur->data;
}

void LinkedList::insertFront(int x) {
    cout << "\nInsert Front: " << x << endl;

    print();
    this_thread::sleep_for(chrono::milliseconds(250));

    cout << "\nNew Node: [ " << x << " ]\n";
    cout << "Linking to Head...\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    n++;

    cout << "\nResult:\n";
    print();
}

void LinkedList::insertBack(int x) {
    cout << "\nInsert Back: " << x << endl;

    print();
    this_thread::sleep_for(chrono::milliseconds(250));

    cout << "\nTraversing to tail...\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    Node* newNode = new Node(x);

    if (empty()) {
        head = newNode;
    }
    else {
        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = newNode;
    }
    n++;

    cout << "\nResult:\n";
    print();
}

void LinkedList::removeFront() {
    if (empty()) {
        cout << "List is empty\n";
        return;
    }

    cout << "\nRemove Front: " << head->data << endl;

    print();
    this_thread::sleep_for(chrono::milliseconds(150));

    cout << "\nRemoving head node...\n";
    this_thread::sleep_for(chrono::milliseconds(250));

    Node* temp = head;
    head = head->next;
    delete temp;
    n--;

    cout << "\nResult:\n";
    print();
}

void LinkedList::removeBack() {
    if (empty()) {
        cout << "List is empty\n";
        return;
    }

    cout << "\nRemove Back\n";

    print();
    this_thread::sleep_for(chrono::milliseconds(150));

    if (head->next == nullptr) {
        cout << "Removing: " << head->data << endl;
        delete head;
        head = nullptr;
        n--;
    }
    else {
        Node* cur = head;
        while (cur->next->next != nullptr)
            cur = cur->next;

        cout << "Removing: " << cur->next->data << endl;
        delete cur->next;
        cur->next = nullptr;
        n--;
    }

    this_thread::sleep_for(chrono::milliseconds(250));

    cout << "\nResult:\n";
    print();
}

void LinkedList::print() {
    cout << "\nHead\n ↓\n";

    if (empty()) {
        cout << "NULL\n";
        return;
    }

    Node* cur = head;
    while (cur != nullptr) {
        cout << "[ " << cur->data << " ]";
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

void listMenu() {
    LinkedList list;
    int choice, x;

    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Back\n";
        cout << "3. Remove Front\n";
        cout << "4. Remove Back\n";
        cout << "5. Front\n";
        cout << "6. Back\n";
        cout << "7. Size\n";
        cout << "8. Empty\n";
        cout << "9. Print\n";
        cout << "0. Back\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> x;
            list.insertFront(x);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> x;
            list.insertBack(x);
        }
        else if (choice == 3) list.removeFront();
        else if (choice == 4) list.removeBack();
        else if (choice == 5) cout << "Front: " << list.front() << endl;
        else if (choice == 6) cout << "Back: " << list.back() << endl;
        else if (choice == 7) cout << "Size: " << list.size() << endl;
        else if (choice == 8) cout << (list.empty() ? "Empty\n" : "Not Empty\n");
        else if (choice == 9) list.print();
        else if (choice == 0) break;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n==== Data Structure Visualizer ====\n";
        cout << "1. Linked List\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) listMenu();
        else if (choice == 0) break;
    }

    return 0;
}
