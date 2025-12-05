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
    Queue q;
public:
    void push(int x) {
        q.enqueue(x);
        int s = q.size();
        for (int i = 0; i < s - 1; i++)
            q.enqueue(q.dequeue());
    }
    void pop() {
        if (q.isEmpty()) cout << "Stack empty\n";
        else cout << q.dequeue() << " popped\n";
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.push(25);
    st.pop();
    st.pop();
    return 0;
}