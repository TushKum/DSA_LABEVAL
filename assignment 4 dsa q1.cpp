#include <iostream>
using namespace std;

#define MAX 100

class SimpleQueue {
    int arr[MAX];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) { 
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    SimpleQueue q;
    int choice, val;

    do {
        cout << "\n--- Simple Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}