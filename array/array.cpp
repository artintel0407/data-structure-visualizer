#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Array {
private:
    int* arr;
    int capacity;

public:
    Array(int cap = 10);
    ~Array();

    int size();
    int at(int idx);
    void set(int idx, int value);
    void insert(int idx, int value);
    void erase(int idx);
    void print();
};

Array::Array(int cap)
    : capacity(cap) {
    arr = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        arr[i] = 0;
    }
}

Array::~Array() {
    delete[] arr;
}

int Array::size() {
    return capacity;
}

int Array::at(int idx) {
    if (idx < 0 || idx >= capacity) {
        cout << "Invalid index\n";
        return -1;
    }
    return arr[idx];
}

void Array::set(int idx, int value) {
    if (idx < 0 || idx >= capacity) {
        cout << "Invalid index\n";
        return;
    }

    cout << "\nSet index " << idx << " to " << value << endl;
    this_thread::sleep_for(chrono::milliseconds(200));

    arr[idx] = value;

    cout << "\nResult:\n";
    print();
}

void Array::insert(int idx, int value) {
    if (idx < 0 || idx >= capacity) {
        cout << "Invalid index\n";
        return;
    }

    cout << "\nInsert " << value << " at index " << idx << endl;

    print();
    this_thread::sleep_for(chrono::milliseconds(250));

    cout << "\nShifting elements to the right...\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    // 뒤에서부터 밀기 (마지막 값은 사라짐)
    for (int i = capacity - 1; i > idx; i--) {
        arr[i] = arr[i - 1];
    }

    arr[idx] = value;

    cout << "\nResult:\n";
    print();
}

void Array::erase(int idx) {
    if (idx < 0 || idx >= capacity) {
        cout << "Invalid index\n";
        return;
    }

    cout << "\nErase element at index " << idx << endl;

    print();
    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "\nShifting elements to the left...\n";
    this_thread::sleep_for(chrono::milliseconds(250));

    for (int i = idx; i < capacity - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // 마지막은 0으로 초기화
    arr[capacity - 1] = 0;

    cout << "\nResult:\n";
    print();
}

void Array::print() {
    cout << "\nIndex: ";
    for (int i = 0; i < capacity; i++) {
        cout << i;
        if (i < 10) cout << "    ";
        else cout << "   ";
    }
    cout << "\n";

    cout << "Value: ";
    for (int i = 0; i < capacity; i++) {
        if (arr[i] < 10 && arr[i] > -10)
            cout << "[ " << arr[i] << " ] ";
        else
            cout << "[" << arr[i] << "] ";
    }
    cout << "\n";
}

void arrayMenu() {
    int cap;
    cout << "Enter array capacity: ";
    cin >> cap;

    Array a(cap);
    int choice, idx, value;

    while (true) {
        cout << "\n--- Array Menu ---\n";
        cout << "1. At\n";
        cout << "2. Set\n";
        cout << "3. Insert\n";
        cout << "4. Erase\n";
        cout << "5. Size\n";
        cout << "6. Print\n";
        cout << "0. Back\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter index: ";
            cin >> idx;
            int result = a.at(idx);
            if (idx >= 0 && idx < a.size())
                cout << "Value: " << result << endl;
        }
        else if (choice == 2) {
            cout << "Enter index and value: ";
            cin >> idx >> value;
            a.set(idx, value);
        }
        else if (choice == 3) {
            cout << "Enter index and value: ";
            cin >> idx >> value;
            a.insert(idx, value);
        }
        else if (choice == 4) {
            cout << "Enter index: ";
            cin >> idx;
            a.erase(idx);
        }
        else if (choice == 5) {
            cout << "Size: " << a.size() << endl;
        }
        else if (choice == 6) {
            a.print();
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
        cout << "1. Array\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> choice;

        if (choice == 1) arrayMenu();
        else if (choice == 0) break;
    }

    return 0;
}
