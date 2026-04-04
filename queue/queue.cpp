#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    friend class Queue;
public:
    explicit Node(int data)
        : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
    int n;

public:
    Queue();
    ~Queue();
    int size();
    bool empty();
    int front();
    void enqueue(int x);
    void dequeue();
    void print();
};

Queue::Queue()
    : head(nullptr), tail(nullptr), n(0) {}

Queue::~Queue() {
    while (!empty()) dequeue();
}

int Queue::size() {
    return n;
}

bool Queue::empty() {
    return n == 0;
}

int Queue::front() {
    if (empty()) return -1;
    return head->data;
}

void Queue::enqueue(int x) {
    cout << "\nEnqueue: " << x << endl;

    // 1단계: 기존 상태 출력
    print();
    this_thread::sleep_for(chrono::milliseconds(250));

    // 2단계: 추가될 노드 표시
    cout << "\nNew Node: [ " << x << " ]\n";
    cout << "Linking to previous Rear...\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    // 실제 삽입
    Node* newNode = new Node(x);

    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    n++;

    // 3단계: 결과 출력
    cout << "\nResult:\n";
    print();
}

void Queue::dequeue() {
    if (empty()) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "\nDequeue: " << head->data << endl;

    // 1단계: 현재 상태
    print();
    this_thread::sleep_for(chrono::milliseconds(150));

    // 2단계: 제거 표시
    cout << "\nRemoving Front: [ " << head->data << " ]\n";
    this_thread::sleep_for(chrono::milliseconds(250));

    // 실제 삭제
    Node* temp = head;
    head = head->next;
    delete temp;
    n--;

    if (head == nullptr) {
        tail = nullptr;
    }

    // 3단계: 결과 출력
    cout << "\nResult:\n";
    print();
}

void Queue::print() {
    Node* cur = head;

    cout << "\nFront                         Rear\n";

    if (empty()) {
        cout << "NULL\n";
        return;
    }

    while (cur != nullptr) {
        cout << "[ " << cur->data << " ]";
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

void queueMenu() {
    Queue q;
    int choice, x;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Empty\n";
        cout << "6. Print\n";
        cout << "0. Back\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> x;
            q.enqueue(x);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            cout << "Front: " << q.front() << endl;
        }
        else if (choice == 4) {
            cout << "Size: " << q.size() << endl;
        }
        else if (choice == 5) {
            cout << (q.empty() ? "Empty\n" : "Not Empty\n");
        }
        else if (choice == 6) {
            q.print();
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
        cout << "1. Queue\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) queueMenu();
        else if (choice == 0) break;
    }

    return 0;
}
