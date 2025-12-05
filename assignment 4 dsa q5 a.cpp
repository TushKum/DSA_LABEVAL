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
};

class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) q2.enqueue(q1.dequeue());
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() {
        if (q1.isEmpty()) cout << "Stack empty\n";
        else cout << q1.dequeue() << " popped\n";
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.pop();
    return 0;
}

