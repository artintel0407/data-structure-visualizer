#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    friend class Stack;
public:
    explicit Node(int data)
        : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* head;
    int n;
public:
    Stack();
    ~Stack();
    int size();
    bool empty();
    int top();
    void push(int x);
    void pop();
    void print();
};
Stack::Stack()
    : head(nullptr), n(0) {}
Stack::~Stack() {
    while (!empty()) pop();
}

int Stack::size() {
    return n;
}

bool Stack::empty() {
    return n == 0;
}

int Stack::top() {
    if (empty()) return -1;
    return head->data;
}

void Stack::push(int x) {
    cout << "Pushing: " << x << endl;

    Node* newNode = new Node(x);
    head->next = head;
    head = newNode;
    n++;
}

void Stack::pop() {
    if (empty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Popping: " << head->data << endl;
    
    Node* temp = head;
    head = head->next;
    delete temp;
    n--;
}

void Stack::print() {
    Node* cur = head;
    cout << "\nTop\n ↓\n";

    while (cur != nullptr) {
        cout << "[ " << cur->data << " ]\n";
        cur = cur->next;
    }
    cout << "NULL\n";
}


void stackMenu() {
    Stack s;
    int choice, x;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Empty\n";
        cout << "6. Print\n";
        cout << "0. Back\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> x;
            s.push(x);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            cout << "Top: " << s.top() << endl;
        }
        else if (choice == 4) {
            cout << "Size: " << s.size() << endl;
        }
        else if (choice == 5) {
            cout << (s.empty() ? "Empty\n" : "Not Empty\n");
        }
        else if (choice == 6) {
            s.print();
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
        cout << "1. Stack\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) stackMenu();
        else if (choice == 0) break;
    }

    return 0;
}
