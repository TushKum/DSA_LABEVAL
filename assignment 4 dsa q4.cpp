#include <iostream>
using namespace std;

#define MAX 256

class Queue {
    char arr[MAX];
    int front, rear;

public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(char c) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = c;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else front++;
    }

    char frontVal() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Queue q;
    int freq[256] = {0};

    for (char c : s) {
        freq[c]++;
        q.enqueue(c);

        while (!q.isEmpty() && freq[q.frontVal()] > 1)
            q.dequeue();

        if (q.isEmpty()) cout << -1 << " ";
        else cout << q.frontVal() << " ";
    }
    cout << "\n";
    return 0;
}