#include <iostream>
using namespace std;

#define MAX 100

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
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