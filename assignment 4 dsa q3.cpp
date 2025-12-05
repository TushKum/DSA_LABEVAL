#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }

    int size() { return (isEmpty() ? 0 : rear - front + 1); }

    void display() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    void interleave() {
        int n = size();
        if (n % 2 != 0) {
            cout << "Queue size must be even.\n";
            return;
        }

        int half = n / 2;
        int firstHalf[MAX], secondHalf[MAX];
        int fSize = 0, sSize = 0;

        for (int i = 0; i < half; i++) firstHalf[fSize++] = dequeue();
        for (int i = 0; i < half; i++) secondHalf[sSize++] = dequeue();

        // merge back interleaving
        for (int i = 0; i < half; i++) {
            enqueue(firstHalf[i]);
            enqueue(secondHalf[i]);
        }
    }
};

int main() {
    Queue q;
    int n, x;

    cout << "Enter even number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cout << "Original Queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}